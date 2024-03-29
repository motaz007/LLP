#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"

/*
 * function to setup the timer 
 */
void setupTimer(uint16_t period)
{
	/*
	 * TODO enable and set up the timer
	 * 
	 * 1. Enable clock to timer by setting bit 6 in CMU_HFPERCLKEN0 2.
	 * Write the period to register TIMER1_TOP 3. Enable timer interrupt
	 * generation by writing 1 to TIMER1_IEN 4. Start the timer by writing 
	 * 1 to TIMER1_CMD
	 * 
	 * This will cause a timer interrupt to be generated every (period)
	 * cycles. Remember to configure the NVIC as well, otherwise the
	 * interrupt handler will not be invoked. 
	 */
	 

	*CMU_HFPERCLKEN0 |= CMU2_HFPERCLKEN0_TIMER1;	  //setting 6 in CMU_HFPERCLKEN0
	*TIMER1_TOP = period;  // timer period after which will reset
	*TIMER1_IEN |= 1U;  // use 1U which 1 unsigned too (compilers give warnings when comparing a signed and an unsigned values)
//	*TIMER1_CMD |= 1U; // Start the timer
	
	

}

