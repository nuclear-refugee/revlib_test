/**
 * @file ASA_UARTS.c
 * @author LiYu
 * @date 2018.03.06
 * @brief Basic test of serial io.
 */


#include "revlib/rev_DEVICE.h"
#include "revlib/rev_serial.h"

int main() {
    rev_serial_init();

    printf("Hello world \n");
    printf("Serial test 2017.11.04\n");
    
    char s[20];
    scanf("%s", s);
    printf("input s: %s\n", s);
    
    return 0;
}
