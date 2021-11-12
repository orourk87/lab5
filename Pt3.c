#include "msp430G2553.h"
void main(void)
{
 WDTCTL = WDTPW + WDTHOLD;  // Stop WDT

 P1DIR |= BIT6;             // P1.6 to output
 TA0CTL = TASSEL_2 + MC_1+ID_3+TACLR;//+TACLR;

 TA0CCR0 = 31250-1; // Set maximum count value (PWM Period
 TA0CCR1 = 6250-1; // initialise counter compare value

 TA0CCTL0 |= CCIE; // compare interrupt
 TA0CCTL1 |= CCIE; // compare interrupt

 TA0CCTL0 &=~CCIFG;// clear the interrupt flag
 TA0CCTL1 &=~CCIFG;// clear the interrupt flag

 _enable_interrupts(); // Enter LPM0
}
#pragma vector = TIMER0_A0_VECTOR       //define the interrupt service vector
__interrupt void TA0_ISR (void)    // interrupt service routine
    {
    P1OUT |=BIT6;       // set output to green led
    TA0CCTL0 &=~CCIFG;// clear the interrupt flag
    }

#pragma vector = TIMER0_A1_VECTOR       //define the interrupt service vector
__interrupt void TA1_ISR (void)    // interrupt service routine
    {
    P1OUT &=~BIT6;   // set the output to green led
    TA0CCTL1 &=~CCIFG;  // clear the interrupt flag

    }
