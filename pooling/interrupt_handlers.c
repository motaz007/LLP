#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"

/*
 * TIMER1 interrupt handler 
 */
void __attribute__ ((interrupt)) TIMER1_IRQHandler()
{
	/*
	 * TODO feed new samples to the DAC remember to clear the pending
	 * interrupt by writing 1 to TIMER1_IFC 
	 */
	 
	
		
		*DAC0_CH0DATA = 0x555 ;
		*DAC0_CH1DATA = 0x555 ;
		*TIMER1_IFC  = 1;
	}

/*
 * GPIO even pin interrupt handler 
 */
void __attribute__ ((interrupt)) GPIO_EVEN_IRQHandler()
{
	/*
	 * TODO handle button pressed event, remember to clear pending
	 * interrupt 
	 */
	 
		if  ( (*TIMER1_CNT > 270)  && (*GPIO_PC_DIN & 0xff) == (((~(1 << 0)) )&0xff)  ){
	*TIMER1_CMD |= 1U; // Start the timer
	
	}else
		*TIMER1_CMD |= 2U; // Stop the timer
		
		*GPIO_IFC = *GPIO_IEN; // clear the interrupt
}

/*
 * GPIO odd pin interrupt handler 
 */
void __attribute__ ((interrupt)) GPIO_ODD_IRQHandler()
{
	/*
	 * TODO handle button pressed event, remember to clear pending
	 * interrupt 
	 */
	 
		if  ( (*TIMER1_CNT > 270)  && (*GPIO_PC_DIN & 0xff) == (((~(1 << 0)) )&0xff)  ){
	*TIMER1_CMD |= 1U; // Start the timer
	
	}else
		*TIMER1_CMD |= 2U; // Stop the timer
		
	*GPIO_IFC = *GPIO_IEN; // clear the interrupt
}
