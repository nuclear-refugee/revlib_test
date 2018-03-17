#include "../../revlib/ASA/ASA_UARTS.h"
#include "../../revlib/ASA/buffer.h"

#include <inttypes.h>
#include "stdio.h"

// NOTE The HEADER is not assigned in the datasheet yet, so the value 
//      is temporary now!!
#define UART_HEADER 0xF0 ///< The HEADER of ASA_UART packet.

#define UART_WR 7 ///< The bit to controll write command or read command in RAdd.

// NOTE The UART_UID is not assigned in the datasheet yet, so the value 
//      is temporary now!!
#define UART_UID 0x12 ///< The bit to controll write command or read command in RAdd.

#define BUFFERSIZE 255

extern Buf_t BufIn;
extern Buf_t BufOut;

uint8_t uart_get() {
    return 0;
};

uint8_t uart_put(uint8_t data){
    return 0;
};
void print_bufin();

int main() {
    printf("Start!\n");
    uint8_t byte = 2; 
    uint8_t address = 2; 
    buf_write(&BufIn, UART_HEADER);
    buf_write(&BufIn, UART_UID);
    buf_write(&BufIn, address | (1<<UART_WR)); // write mode
    buf_write(&BufIn, byte);
    buf_write(&BufIn, 1);
    buf_write(&BufIn, 2);
    buf_write(&BufIn, UART_HEADER + UART_UID + (address | (1<<UART_WR)) + byte +1 +2);
    print_bufin();
    
    uint8_t res = 0;
    uint8_t i   = 0;
    while (i < 100) {
        i++;
        res = uarts_decode_buf_step();
        if (UartDecoder.status == status_done) {
            break;
        }
    }
    printf("res = %d-----------------------\n", res);
    printf("uid = %d\n", UartDecoder.uid);
    printf("wr = %d\n", UartDecoder.wr);
    printf("address = %d\n", UartDecoder.address);
    printf("bytes = %d\n", UartDecoder.bytes);
    printf("chksum = %d\n", UartDecoder.chksum);
    
    return 0;
}

void print_bufin() {
    printf("s:%3d\n", BufIn.s);
    printf("e:%3d\n", BufIn.e);
    for (uint16_t i = BufIn.s; i < BufIn.e; i++) {
        printf("%4d", BufIn.data[i]);
    }
    printf("\n");
}
// struct BUFFER {
//     uint8_t data[255];
//     uint8_t s; ///< The start index of data array
//     uint8_t e; ///< The end index of data array
// };

// struct UartDecoder {
//     enum uarts_status status;
//     uint8_t uid;
//     uint8_t wr;
//     uint8_t address;
//     uint8_t bytes;
//     uint8_t data[256];
//     uint8_t chksum;
// };
