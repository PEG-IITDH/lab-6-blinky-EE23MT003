#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
int main(void)
{
 SYSCTL_RCGC2_R |= 0x00000020;
 GPIO_PORTF_LOCK_R = 0x4C4F434B;
 GPIO_PORTF_CR_R = 0x01;
 GPIO_PORTF_DIR_R = 0x0E;
 GPIO_PORTF_DEN_R = 0x1F;
 GPIO_PORTF_PUR_R = 0x11;
 while(1)
 {
 unsigned int sw1= GPIO_PORTF_DATA_R & 0x10;
 if(sw1 == 0x00)
 {
 GPIO_PORTF_DATA_R |= 0x02;
 }
 else
 {
 GPIO_PORTF_DATA_R = 0x00;
 }
 }
}
