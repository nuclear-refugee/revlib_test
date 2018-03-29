/**
 * @file s_rec.m88.c
 * @author LiYu
 * @date 2018.03.18
 * @brief Slave test of ASA_UARTM_rec on m88
 */

#include "../../revlib/rev_DEVICE.h"
#include "../../revlib/rev_serial.h"
#include "../../revlib/ASA/ASA_UARTS.h"
#include "../../revlib/ASA/ASA_UART_PAC.h"
#include "../../revlib/buffer.h"

extern Buf_t BufIn;

int main() {
    uart_init();
    uart_en_int_rx(1);
    uart_en_int_tx(1);
    sei();
    uint8_t res = 0;
    uint8_t data[3] = {1,2,3};

    while(1) {
        res = uart_decode_buf_step();
        sei();
        if (UartDecoder.state == state_done) {
            uart_put(1);
            uart_encoder(0, 0, 127, 3, data);
            UartDecoder.state = state_header;
        }
    }
    return 0;
}

ISR(USART_RX_vect) {
    uart_rx_handle();
}

ISR(USART_TX_vect) {
    uart_tx_handle();
}
