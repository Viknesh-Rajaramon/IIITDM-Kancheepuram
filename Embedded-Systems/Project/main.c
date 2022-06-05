#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "tm4c123gh6pm.h"

/* Show numbers in 7 Segment Display (Common Anode) */
int numbers[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

/* Delay function */
void delayMs(int n)
{
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < 3180; ++j)
      ;
}

/* Read Char by Char from Computer to RX FIFO buffer */
char readChar(void)
{
  char c;
  
  while((UART0_FR_R & (1 << 4)) != 0);
  
  c = UART0_DR_R;
  
  return c;
}

/* Read String from Computer through readchar() function */
char *readString(char delimiter)
{
  int stringSize = 0;
  char *string = (char *)calloc(10, sizeof(char));
  char c = readChar();
  
  while(c != delimiter)
  {
    *(string + stringSize) = c;
    stringSize++;
    c = readChar();
  }
  
  return string;
}

/* Initializing the GPIO ports for UART communication */
void UART_init()
{
  SYSCTL_RCGCUART_R |= (1 << 0); // Enable UART0 Module
  SYSCTL_RCGCGPIO_R |= (1 << 0); // Enable clock to PORTA
  
  GPIO_PORTA_AFSEL_R = (1 << 1) | (1 << 0); // Enable PA0 and PA1 As Alternate Function PIN
  GPIO_PORTA_PCTL_R |= (1 << 0) | (1 << 1); // Make PA0, PA1 UART output pin
  GPIO_PORTA_DEN_R |= (1 << 0) | (1 << 1);  // Enable digital pins PA0, PA1
  
  UART0_CTL_R &= ~(1 << 0);                     // Disable the UART by clearing the UARTEN
  UART0_IBRD_R = 104;                           // Integer portion of the BRD
  UART0_FBRD_R = 11;                            // Fractional portion of the BRD
  UART0_LCRH_R = (0x3 << 5) | (1 << 4);         // 8-bit, no parity, 1-stop bit
  UART0_CTL_R = (1 << 0) | (1 << 8) | (1 << 9); // Enable the UART by setting the UARTEN bit
}

/* Initialize GPIO Ports for displaying minutes in 7 Segment Display */
void minutes_display_init(void)
{
  GPIO_PORTB_CR_R |= 0x7F;        // Allow changes to PB0-PB6
  GPIO_PORTB_AMSEL_R = 0x00;      // Disable analog function
  GPIO_PORTB_PCTL_R = 0x00000000; // GPIO clear bit PCTL
  GPIO_PORTB_DIR_R |= 0x7F;       // Set PB6-PB0 as outputs
  GPIO_PORTB_DEN_R |= 0x7F;       // Enable digital pins PB6-PB0
}

/* Initialize GPIO Ports for displaying seconds in 7 Segment Display */
void seconds_display_init(void)
{
  /* Second Position 1 - Denotes seconds in multiples of 10 (0, 10, 20, 30, 40, 50) */
  GPIO_PORTE_CR_R |= 0xFF;        // Allow changes to PE0-PE5
  GPIO_PORTE_AMSEL_R = 0x00;      // Disable analog function
  GPIO_PORTE_PCTL_R = 0x00000000; // GPIO clear bit PCTL
  GPIO_PORTE_DIR_R |= 0x3F;       // Set PE0-PE5 as outputs
  GPIO_PORTE_DEN_R |= 0xFF;       // Enable digital pins PE0-PE5
  
  /* Second Position 2 - Denotes seconds in multiples of 1 (0, 1, 2, 3, 4, 5, 6, 7, 8, 9) */
  GPIO_PORTA_CR_R |= 0xFF;        // Allow changes to PA2-PA7
  GPIO_PORTA_AMSEL_R = 0x00;      // Disable analog function
  GPIO_PORTA_PCTL_R = 0x00000000; // GPIO clear bit PCTL
  GPIO_PORTA_DIR_R |= 0xFF;       // Set PA2-PA7 as outputs
  GPIO_PORTA_DEN_R |= 0xFF;       // Enable digital pins PA2-PA7
  
  /* PORT D Used in Second Position 1 and 2 */
  GPIO_PORTD_CR_R |= 0xFF;        // Allow changes to PD0, PD7
  GPIO_PORTD_AMSEL_R = 0x00;      // Disable analog function
  GPIO_PORTD_PCTL_R = 0x00000000; // GPIO clear bit PCTL
  GPIO_PORTD_DIR_R |= 0x81;       // Set PD0, PD7 as outputs
  GPIO_PORTD_DEN_R |= 0x81;       // Enable digital pins PD0, PD7
}

/* Initialize GPIO Ports for Buzzer */
void buzzer_init(void)
{
  GPIO_PORTF_DEN_R |= (1 << 4);  // Enable PF4 as digital pin
  GPIO_PORTF_DIR_R |= (1 << 4);  // Configure PF4 as digital output pins
}

/* Get number of minutes from user through UART */
int UART(void)
{
  char *string = readString('\r');
  int time = 0;
  
  volatile int i = 0;
  
  while(*(string + i) != '\0')
  {
    time = time * 10 + (*(string + i) - '0');
      i += 1;
  }
  
  return time;
}

/* Display minutes remaining in 7 Segment Display */
void minutes_display(int min)
{
  /* Minutes Position - Denotes minutes
  _________________________________
  | TM4C Pin | Individual Segment |
  |__________|____________________|
  |    PB0   |          a         |
  |    PB1   |          b         |
  |    PB2   |          c         |
  |    PB3   |          d         |
  |    PB4   |          e         |
  |    PB5   |          f         |
  |    PB6   |          g         |
  |__________|____________________|
  */
  
  GPIO_PORTB_DATA_R = numbers[min];
}

/* Display seconds remaining in 7 Segment Display */
void seconds_display(int sec)
{
  /* Second Position 1 - Denotes seconds in multiples of 10 (0, 10, 20, 30, 40, 50)
  _________________________________
  | TM4C Pin | Individual Segment |
  |__________|____________________|
  |    PE0   |          a         |
  |    PE1   |          b         |
  |    PE2   |          c         |
  |    PE3   |          d         |
  |    PE4   |          e         |
  |    PE5   |          f         |
  |    PD0   |          g         |
  |__________|____________________|
  */
  
  int s1 = sec / 10;
  int value = (numbers[s1] << 1);
  value = (value >> 1);
  GPIO_PORTE_DATA_R = value;
  GPIO_PORTD_DATA_R = (value >> 6);
  
  /* Second Position 2 - Denotes seconds in multiples of 1 (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)
  _________________________________
  | TM4C Pin | Individual Segment |
  |__________|____________________|
  |    PA2   |          a         |
  |    PA3   |          b         |
  |    PA4   |          c         |
  |    PA5   |          d         |
  |    PA6   |          e         |
  |    PA7   |          f         |
  |    PD7   |          g         |
  |__________|____________________|
  */
  
  int s2 = sec % 10;
  value = (numbers[s2] << 1);
  value = (value >> 1);
  GPIO_PORTA_DATA_R = (value << 2);
  value = (value >> 6);
  GPIO_PORTD_DATA_R |= (value << 7);
}

/* Function for implementing timer */
void timer(int min)
{
  minutes_display(min);    // Display minutes in 7 Segment display
  seconds_display(0);      // Display Seconds in 7 Segment Display
  
  for(int i = min - 1; i >= 0; --i)
  {
    for(int j = 59; j >= 0; --j)
    {
      delayMs(1000);      // Delay 1 second (1000 ms = 1 second)
      minutes_display(i); // Display minutes in 7 Segment display
      seconds_display(j); // Display Seconds in 7 Segment Display
    }
  }
}

/* Function to indicate that timer is up (by sound) */
void buzzer(int n)
{
  for(int i = 0; i < 5; ++i)
  {
    GPIO_PORTF_DATA_R |= (1 << 4);
    delayMs(100);
    GPIO_PORTF_DATA_R &= 0xEF;
    delayMs(1000);
  }
}

int main()
{
  SYSCTL_RCGCGPIO_R = (1 << 0) | (1 << 1) | (1 << 3) | (1 << 4) | (1 << 5);  // Enable clock for PORT A, B, D, E, F
  GPIO_PORTF_DATA_R = (0 << 4);
  int count = 2;
  /*
  UART_init();
  count = UART();
*/
  
  minutes_display_init();
  seconds_display_init();
  buzzer_init();
  
  timer(count);
  
  buzzer(5);
}