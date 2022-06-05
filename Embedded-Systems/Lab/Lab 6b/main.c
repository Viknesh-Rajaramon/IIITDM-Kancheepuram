#include <stdint.h> 
#include "tm4c123gh6pm.h"

#define BUTTON_PRESS 0x00U // Value when SW1 or SW2 Button is pressed

#define LEFT_BUTTON *((unsigned int *) 0x40025040) // Address of PF4 Switch 1
#define RIGHT_BUTTON *((unsigned int *) 0x40025004) // Address of PF0 Switch 2

/* Delay 'n' milli seconds */
/* 16 MHz Clock */
void delayMs(int n)
{
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0; j < 3180; j++) ; // Do nothing for 1 milli second
    }
}

int main()
{
  /* Button */
  SYSCTL_RCGCGPIO_R = 0x20U; // Clock gating register to enable the clock on GPIO F port
  GPIO_PORTF_DIR_R = 0x0EU; // Direction for input/output
  GPIO_PORTF_DEN_R = 0x1FU; // Digital function enabled on PF1,PF2,PF3 
  GPIO_PORTF_CR_R = 0xFFU; // Set GPIOCR register for PF4 and PF0 to allow write access (SW1 is connected to PF4 and SW2 is connected to PF0 where Pull-up needs to be enabled)
  GPIO_PORTF_PUR_R = 0x11U; // Enable Pull-Up Resistor for PF4 and PF0
  GPIO_PORTF_LOCK_R = 0x4C4F434BU; // Unlocks GPIOCR register for write access
  
  int duty_cycle_values[] = {0, 30, 60, 100};
  int counter = 1;
  
  int buttonPressed_Switch = 0;
  int buttonPressed_Select = 0;
  int clockwise = 1;

  SYSCTL_RCGCPWM_R |= 0x02; // Enable Clock to PWM1
  SYSCTL_RCGCGPIO_R |= 0x20; // enable clock to GPIOF
  SYSCTL_RCGCGPIO_R |= 0x02; // enable clock to GPIOB

  SYSCTL_RCC_R &= ~0x00100000; // Use System Clock for PWM
  PWM1_INVERT_R |= 0x80; // Positive Pulse
  PWM1_3_CTL_R = 0; // Disable PWM1_3 during Configuration
  PWM1_3_GENB_R = 0x0000080C; // Output High when Load and Low when Match
  PWM1_3_LOAD_R = 3999; // 4 KHz
  PWM1_3_CTL_R = 1; // Enable PWM1_3
  PWM1_ENABLE_R |= 0x80; // Enable PWM1

  GPIO_PORTF_DIR_R |= 0x08; // Set PF3 Pins as Output (LED) pin
  GPIO_PORTF_DEN_R |= 0x08; // Set PF3 Pins as Digital Pins
  GPIO_PORTF_AFSEL_R |= 0x08; // Enable Alternate Function
  GPIO_PORTF_PCTL_R &= ~0x0000F000; // Clear PF3 Alternate Function
  GPIO_PORTF_PCTL_R |= 0x00005000; // Set PF3 Alternate Funtion to PWM

  GPIO_PORTB_DEN_R |= 0x0C; // PB3 as Digital Pins
  GPIO_PORTB_DIR_R |= 0x0C; // Set PB3 as Output
  GPIO_PORTB_DATA_R |= 0x08; // Enable PB3

  while(1)
  {
    // Main Code
    if((buttonPressed_Select) == 0 && (LEFT_BUTTON == BUTTON_PRESS))
    {
      buttonPressed_Select = 1;
      PWM1_3_CMPB_R = 75 * duty_cycle_values[counter];
      counter = (counter + 1) % (sizeof(duty_cycle_values) / sizeof(duty_cycle_values[0]));
    }
    
    else if((buttonPressed_Select == 1) && (LEFT_BUTTON != BUTTON_PRESS))
    {
      buttonPressed_Select = 0;
    }
	
    if((buttonPressed_Switch == 0) && (RIGHT_BUTTON == BUTTON_PRESS))
    {
      buttonPressed_Switch = 1;
      
      if(clockwise == 1)
      {
	GPIO_PORTB_DATA_R &= ~0x04;
	GPIO_PORTB_DATA_R |= 0x08;
      }
      
      else 
      {
	GPIO_PORTB_DATA_R &= ~0x08;
	GPIO_PORTB_DATA_R |= 0x04;
      } 
      
      clockwise = ~clockwise;
    }
    
    else if((buttonPressed_Switch == 1) && (RIGHT_BUTTON != BUTTON_PRESS))
    {
      buttonPressed_Switch = 0;
    }
  }
}