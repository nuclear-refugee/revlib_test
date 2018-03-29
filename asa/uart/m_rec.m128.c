/**
 * @file m_rec.m128.c
 * @author LiYu
 * @date 2018.03.18
 * @brief Master test of ASA_UARTM_rec on m128
 */

#define UART_UID 0x12 ///< The bit to controll write command or read command in RAdd.

#include "../../revlib/rev_DEVICE.h"
#include "../../revlib/rev_serial.h"
#include "../../revlib/ASA/ASA_UARTM.h"
#include "../../revlib/ASA/ASA_UART_PAC.h"
#include "../../revlib/ASA/ASA_general.h"
#include "../../revlib/buffer.h"

void sla_rst();
extern Buf_t BufIn;

int main() {
    rev_serial_init();
    uint8_t ch;

    printf("UARTM test 2017.03.17\n");

    uint8_t data[3] = {0,1,2};
    sla_rst();
    uart_init();
    uart_en_int_rx(1);
    sei();
    ASA_ID_init();
    ASA_ID_set(1);

    ASA_UARTM_trm(UART_UID, 127, 2, data);

    while (1) {
        if (buf_is_null(BufIn)) {

        } else {
            ch = buf_read(&BufIn);
            printf("0x%02X\n", ch);
        }
        _delay_ms(100);
    }

    return 0;
}

ISR(USART1_RX_vect) {
    uart_rx_handle();
}

void sla_rst() {
    DDRG |= _BV(PG4);
    PORTG &= ~_BV(PG4);
    _delay_ms(28);
    PORTG |= _BV(PG4);
    _delay_ms(70);
}
