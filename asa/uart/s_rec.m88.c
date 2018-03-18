/**
 * @file s_rec.m88.c
 * @author LiYu
 * @date 2018.03.18
 * @brief Slave test of ASA_UARTM_rec on m88
 */

#include "../../revlib/rev_DEVICE.h"
#include "../../revlib/rev_serial.h"
#include "../../revlib/ASA/ASA_UARTS.h"
#include "../../revlib/ASA/buffer.h"

extern Buf_t BufIn;

int main() {
    uart_init();
    uart_en_int_rx(1);
    sei();
    uint8_t res = 0;
    
    while(1) {        
        res = uarts_decode_buf_step();
        if (UartDecoder.status == status_done) {
            _delay_ms(100);
            uart_put(1);
            _delay_ms(100);
            uart_put(2);
            _delay_ms(100);
            uart_put(UartDecoder.status);
            _delay_ms(100);
            uart_put(UartDecoder.uid);
            _delay_ms(100);
            uart_put(UartDecoder.wr);
            _delay_ms(100);
            uart_put(UartDecoder.address);
            _delay_ms(100);
            uart_put(UartDecoder.bytes);
            _delay_ms(100);
            UartDecoder.status = status_header;
        }
        _delay_ms(500);
    }
    return 0;
}

ISR(USART_RX_vect) {
    uarts_rx_handle();
}
