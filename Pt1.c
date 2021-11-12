#include <msp430.h>
#define RedLED BIT6 // set BIT6 to red LED
#define GreenLED BIT0 // set BIT0 to green LED
#define ToggleLeds (P1OUT ^= RedLED|GreenLED) // Set up the toggle function
#define Button BIT3 // set BIT3 to the onboard button
void main(void)
{
    BCSCTL2 |= DIVS_3; // set the clock signal to 1Mhz with a divider of 8
    WDTCTL = WDT_MDLY_32; // divide clock by 32768
    IE1 |= WDTIE; // enbale interrupts for clock
    P1DIR = RedLED|GreenLED; // set the LED to the regsiter 
    P1OUT = RedLED; // sets the inital output to red
    _enable_interrupts(); // enables interrputs
    LPM1; // checks to see if the button is pressed
}
#pragma vector = WDT_VECTOR
    __interrupt void WDT(void)
{
        P1OUT = ToggleLeds; // toggles LEDS
}

