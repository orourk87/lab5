# lab5
(ALL FIGURES AND TABELS ARE FOUND IN THE LAB DOCUMENT)

Part 1:
To configure the clock for part one, first we need to see what the intended output is, and that is a 256ms delay for the toggling of the LEDS. The first line in figure 2 shows the setup for a 1Mhz clock and a clock divider of 8.  The next line also has the clock signal benign divided by 32768.  This is then found to have a value of 3.81 and to find the delay, it would just be the inverse giving a value of 262ms as shown in figure 1.

Part 2:
In Part 2 a duty cycle and period were given to generate a PWM signal to control the LED brightness.  In order to achieve this TACCR0 and TACCR1 need to be calculated out to get the intended output.  These calculations are shown in figure 3.  The MSP430 was then hooked up to an oscilloscope to see if the results for duty cycle and period would match the values that were given.  This is shown in table 1.

Part 3:
Similarly to part 2 a PWM signal had to be generated, but instead of software PWM we used hardware PWM.  This was achieved using interrupts similarly to part 1.  Otherwise Part 1 was very similar to part 2.  TACCR0 and TACCR1 both were calculated in figure 6, and an oscilloscope was used to check the results.  These results are found in table 2.
