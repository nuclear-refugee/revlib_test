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
#include "../../revlib/ASA/ASA_general.h"

int main() {
    rev_serial_init();
    
    printf("UARTM test 2017.03.17\n");
    
    uint8_t data[3] = {0,1,2};
    uart_init();
    ASA_ID_init();
    ASA_ID_set(1);
    
    ASA_UARTM_rec(UART_UID, 127, 2, data);
    while (1) {
        printf("%d\n", uart_get());
    }
    
    return 0;
}
