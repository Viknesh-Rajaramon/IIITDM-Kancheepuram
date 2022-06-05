#include "tm4c123gh6pm.h"

#define RED (1U << 1)
#define BLUE (1U << 2)
#define GREEN (1U << 3)
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)
#define NO_LED ~(RED | GREEN | BLUE)

int main()
{
   volatile int result;
   
   SYSCTL_RCGCGPIO_R = ((1U << 4) | (1U << 5)); // Clock Gating Port E and F
   SYSCTL_RCGCADC_R |= 1; // Analog Gate Gate Enable
   GPIO_PORTF_DIR_R = 0xFFU; // Port F Direction Register
   GPIO_PORTF_DEN_R = 0xFFU; // Port F Digital Function Register
   
   GPIO_PORTE_DIR_R &= ~8; // Disable Digital Function
   GPIO_PORTE_AMSEL_R |= 8; //Enable Analog Function
   
   ADC0_ACTSS_R &= ~8; // Disable SS3 during configuration
   ADC0_EMUX_R &= ~0xF000; // Software Trigger Conversion
   ADC0_SSMUX3_R = 0; // Get Input from Channel 0
   ADC0_SSCTL3_R |= 6; // Take One sample at a time, set flag at first sample
   ADC0_ACTSS_R |= 8; // Enable ADC0 Sequencer 3
   
   while(1)
   {
     ADC0_PSSI_R = 8; // Start Conversion Sequence 3
     
     while((ADC0_RIS_R & 8) == 0); // Wait for conversion completion
   
     result = ADC0_SSFIFO3_R; // Read Conversion Result
      
     // Store result in Port F Data Register
     if(result > 3584)
       GPIO_PORTF_DATA_R = WHITE;
     else if(result > 3072)
       GPIO_PORTF_DATA_R = CYAN;
     else if(result > 2560)
       GPIO_PORTF_DATA_R = MAGENTA;
     else if(result > 2048)
       GPIO_PORTF_DATA_R = YELLOW;
     else if(result > 1536)
       GPIO_PORTF_DATA_R = GREEN;
     else if(result > 1024)
       GPIO_PORTF_DATA_R = BLUE;
     else if(result > 512)
       GPIO_PORTF_DATA_R = RED;
     else
       GPIO_PORTF_DATA_R = NO_LED;
     
     ADC0_ISC_R = 8; // Clear Completion Flag
   }
    
   return 0;
}