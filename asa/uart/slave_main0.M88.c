/**
 * @file ASA_UARTS.c
 * @author LiYu
 * @date 2018.03.06
 * @brief Basic test of serial io.
 */

#include "../../revlib/rev_DEVICE.h"
#include "../../revlib/rev_serial.h"
#include "../../revlib/ASA/ASA_UARTS.h"
#include "../../revlib/ASA/buffer.h"

extern Buf_t BufIn;

int main() {
    uart_init();
    uart_en_int_rx(1);
    uint8_t res = 0;
    sei();
    
    while(1) {
        uart_put(111);
        _delay_ms(100);
        uart_put(res);
        _delay_ms(100);
        uart_put(UartDecoder.status);
        _delay_ms(100);
        uart_put(111);
        _delay_ms(100);
        
        res = uarts_decode_buf_step();
        if (UartDecoder.status == status_done) {
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
        }
        _delay_ms(1000);
    }
    
    return 0;
}

ISR(USART_RX_vect) {
    uarts_rx_handle();
}

// ISR(USART0_TX_vect) {
//     uarts_tx_handle();
// }
