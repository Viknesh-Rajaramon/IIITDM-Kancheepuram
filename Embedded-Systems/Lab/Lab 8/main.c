#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tm4c123gh6pm.h"

/* Question Colours */
#define RED 0x02U
#define YELLOW 0x0AU
#define GREEN 0x08U
#define BLUE 0x04U
#define LIGHTBLUE 0x0CU

/* Answer Colours */
#define WHITE 0x0EU
#define PURPLE 0x06U
#define DARK 0x00U

#define PressedCode 0x00U

/* Delay function */
void delayMs(int n)
{
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < 3180; ++j)
      ;
}

char readChar(volatile int uart)
{
  char c;
  
  if(uart == 0)
  {
    while((UART0_FR_R & (1 << 4)) != 0);
    c = UART0_DR_R;
  }
  else if(uart == 5)
  {
    while((UART5_FR_R & (1 << 4)) != 0);
    c = UART5_DR_R;
  }
  else if(uart == 7)
  {
    while((UART7_FR_R & (1 << 4)) != 0);
    c = UART7_DR_R;
  }
  return c;
}

void printChar(char c, volatile int uart, volatile int flag)
{
  if(flag == 1)
  {
    if(uart == 0)
    {
      while((UART0_FR_R & (1 << 5)) != 0);
      UART0_DR_R = c;
    }
    else if(uart == 5)
    {
      while((UART5_FR_R & (1 << 5)) != 0);
      UART5_DR_R = c;
    }
    else if(uart == 7)
    {
      while((UART7_FR_R & (1 << 5)) != 0);
      UART7_DR_R = c;
    }
  }
}

void printString(char *string, volatile int uart, volatile int flag)
{
  if(flag == 1)
  {
    while(*string)
    {
      printChar(*(string++), uart, flag);
    }
  }
}

char *readString(char delimiter, volatile int uart, volatile int flag)
{
  int stringSize = 0;
  char *string = (char *)calloc(5, sizeof(char));
  char c = readChar(uart);
  printChar(c, uart, flag);

  while(c != delimiter)
  {
    *(string + stringSize) = c; // Put new character at end of Array
    stringSize++;

    if((stringSize % 5) == 0) // String length has reached multiple of 5
    {
      string = (char *) realloc(string, (stringSize + 5) * sizeof(char)); // Adjust string size by increasing size by another 5
    }

    c = readChar(uart);
    printChar(c, uart, flag); // display the character the user typed
  }

  if(stringSize == 0)
  {
    return "\0"; // null character
  }
  return string;
}

int main()
{
  /** PORT F CONFIG **/
  SYSCTL_RCGCGPIO_R |= 0x20U;      // enable clock on PortF
  GPIO_PORTF_DIR_R = 0x0EU;        // make LED pins (PF1, PF2, and PF3) outputs
  GPIO_PORTF_DEN_R = 0x1FU;        // enable digital function on LED pins
  GPIO_PORTF_DATA_R &= ~(0x0EU);   // turn off leds
  GPIO_PORTF_AMSEL_R = 0x00;       // disable analog on PF
  GPIO_PORTF_AFSEL_R = 0x00;       // disable alt funct on PF7-0
  GPIO_PORTF_CR_R = 0xFFU;         // Allow Changes to GPIO Port F
  GPIO_PORTF_PUR_R = 0x11U;        // Enable Pull Up on PF4 & PF0
  GPIO_PORTF_LOCK_R = 0x4C4F434BU; // Unlock GPIO Port F
  GPIO_PORTF_PCTL_R = 0x00000000;  // PCTL GPIO on PF4-0

  /** UART CONFIG **/
  // Enable the UART module using the RCGCUART register.
  SYSCTL_RCGCUART_R |= (1 << 0); // UART0
  SYSCTL_RCGCUART_R |= 0x20;     // UART5
  SYSCTL_RCGCUART_R |= 0x80;     // UART7

  // Enable the clock to the appropriate GPIO module via the RCGCGPIO register
  SYSCTL_RCGCGPIO_R |= (1 << 0);

  // Set the GPIO AFSEL bits for the appropriate pins.
  GPIO_PORTA_AFSEL_R = (1 << 1) | (1 << 0);

  // Configure the GPIO current level and/or slew rate as specified for the mode selected

  // Configure the PMCn fields in the GPIOPCTL register to assign the UART signals to the appropriate pins
  GPIO_PORTA_PCTL_R = (1 << 0) | (1 << 4);

  GPIO_PORTA_DEN_R = (1 << 0) | (1 << 1);

  // Find the Baud-Rate Divisor
  // BRD = 16,000,000 / (16 * 9600) = 104.16666666666666666666666666666666666666666666666666
  // UARTFBRD[DIVFRAC] = integer(0.166667 * 64 + 0.5) = 11

  // With the BRD values in hand, the UART configuration is written to the module in the following order

  // Disable the UART by clearing the UARTEN bit in the UARTCTL register
  UART0_CTL_R &= ~(1 << 0);
  UART5_CTL_R &= ~(1 << 0);
  UART7_CTL_R &= ~(1 << 0);

  // Write the integer portion of the BRD to the UARTIBRD register
  UART0_IBRD_R = 104;
  UART5_IBRD_R = 104;
  UART7_IBRD_R = 104;
  // Write the fractional portion of the BRD to the UARTFBRD register.
  UART0_FBRD_R = 11;
  UART5_FBRD_R = 11;
  UART7_FBRD_R = 11;

  // Write the desired serial parameters to the UARTLCRH register (in this case, a value of 0x0000.0060)
  UART0_LCRH_R = (0x3 << 5) | (1 << 4); // 8-bit, no parity, 1-stop bit
  UART5_LCRH_R = (0x3 << 5) | (1 << 4); // 8-bit, no parity, 1-stop bit
  UART7_LCRH_R = (0x3 << 5) | (1 << 4); // 8-bit, no parity, 1-stop bit

  // Configure the UART clock source by writing to the UARTCC register
  UART0_CC_R = 0x0;
  UART5_CC_R = 0x0;
  UART7_CC_R = 0x0;

  // Enable the UART by setting the UARTEN bit in the UARTCTL register.
  UART0_CTL_R = (1 << 0) | (1 << 8) | (1 << 9);
  UART5_CTL_R = (1 << 0) | (1 << 8) | (1 << 9);
  UART7_CTL_R = (1 << 0) | (1 << 8) | (1 << 9);

  // UART5 TX5 and RX5 use PE4 and PE5. Configure them digital and enable alternate function
  SYSCTL_RCGCGPIO_R |= 0x10;
  GPIO_PORTE_DEN_R = 0x33;         // set PE4 and PE5 as digitasl
  GPIO_PORTE_AFSEL_R = 0x33;       // Use PE4,PE5 alternate function
  GPIO_PORTE_AMSEL_R = 0;          // Turn off analog function
  GPIO_PORTE_PCTL_R |= 0x00110011; // configure PE4 and PE5 for UART
  GPIO_PORTE_CR_R = 0x2F;          // allow changes to PE5,3-0
  GPIO_PORTE_DIR_R |= 0x08;        // PE3 input
  GPIO_PORTE_DIR_R &= ~0x07;       // PE2,PE1,PE0 output
  GPIO_PORTE_PUR_R = 0x08;         // enable pullup resistors on PE3

  /* Question Functions */
  char *Questions[] = {"Are you there in your office?", "Are you happy?", "Are you hungry, want to have lunch?", "Are you thirsty, want to meet for a beverage?", "Shall I come to your office to talk?"};
  int Question_Colour[] = {RED, YELLOW, GREEN, BLUE, LIGHTBLUE};
  char Question_Encoded[] = {(char) 0x30, (char) 0x31, (char) 0x32, (char) 0x33, (char) 0x34};

  /* Answer Functions */
  char *Answers[] = {"Yes", "Maybe", "No"};
  int Answer_Colour[] = {WHITE, PURPLE, DARK};
  char Answer_Encoded[] = {(char) 0x35, (char) 0x36, (char) 0x37};

  volatile int Question_Counter = 0;
  volatile int Answer_Counter = 0;
  volatile int Controller = 0; // Decides which UART is active
  volatile int flag = 0;
  
  volatile int value = 0;
  
  GPIO_PORTF_DATA_R = Question_Colour[Question_Counter];

  while(1)
  {
    value = GPIO_PORTF_DATA_R;
    value = ~value;
    
    if(value & 0x01)
    {
      flag = 1;
    }
    
    if(value & 0x10)
    {
      flag = 0;
    }
    
    if(flag == 0)
    {
      delayMs(500); // Delay for a while to counter bouncing effect

      /* Question Controller */
      if(Controller == 0)
      {
        Question_Counter++;
        Question_Counter %= (sizeof(Question_Colour) / sizeof(Question_Colour[0]));
        GPIO_PORTF_DATA_R = Question_Colour[Question_Counter];
      }
        
      /* Answer Controller */
      else
      {
        Answer_Counter++;
        Answer_Counter %= (sizeof(Answer_Colour) / sizeof(Answer_Colour[0]));
        GPIO_PORTF_DATA_R = Answer_Colour[Answer_Counter];
      }
      delayMs(1000);
    }
    
    else if(flag == 1)
    {
      delayMs(500); // Delay for a while to counter bouncing effect

      /* Send Question */
      if(Controller == 0)
      {
        /* Send Question as encoded */
        printChar(Question_Encoded[Question_Counter], 5, flag);

        /* Receive Question as encoded */
        char val = readChar(7);
        int idx = val - '0';

        printString("Sent Question by 5: ", 0, flag);
        printString(Questions[Question_Counter], 0, flag);
        printString("\n\r", 0, flag);
        printString("Received Question by 7: ", 0, flag);
        printString(Questions[idx], 0, flag);
        printString("\n\r", 0, flag);
      }

      /* Send Answer */
      else if(Controller == 1)
      {
        /* Send Answer as encoded */
        printChar(Answer_Encoded[Answer_Counter], 7, flag);

        /* Receive Answer as encoded */
        char val = readChar(5);
        int idx = val - '5';

        printString("Sent Answer by 7: ", 0, flag);
        printString(Answers[Answer_Counter], 0, flag);
        printString("\n\r", 0, flag);
        printString("Received Answer by 5: ", 0, flag);
        printString(Answers[idx], 0, flag);
        printString("\n\r", 0, flag);
      }
        
      Controller = 1 - Controller;
      Question_Counter = 0;
      Answer_Counter = 0;
      flag = 0;
      GPIO_PORTF_DATA_R = DARK;
      
      delayMs(1000);
    }
  }
}