#include "tm4c123gh6pm.h"

/*
Master SPI Module - Module 0
----------------------------
PA2 - SSI0Clk
PA3 - SSI0Fss
PA4 - SSI0Rx
PA5 - SSI0Tx

Slave SPI Module - Module 2
---------------------------
PB4 - SSI2Clk
PB5 - SSI2Fss
PB6 - SSI2Rx
PB7 - SSI2Tx
*/

/* Function to send data */
void sendChar(char data)
{
  // Wait for Complete Transmission
  while ((SSI0_SR_R & (1 << 0) == 0));
  
  SSI0_DR_R = data;
}

/* Function to Receive a Character from Slave Module */
char recvChar(void)
{
  char c;
  while ((SSI2_SR_R & (1 << 2) == 0));
  
  c = SSI2_DR_R;
  return c;
}

/* Each char stored in TX FIFO buffer and transfer it computer */
void printChar(char c)
{
  while ((UART0_FR_R & (1 << 5)) != 0);
  
  UART0_DR_R = c;
}

/* Print string function send char by char to FIFO txbuffert o comp */
void printString(char *string)
{
  while (*string)
  {
    printChar(*(string++));
  }
}

/* Delay for 'n' Milli Seconds*/
void delayMs(int n)
{
    int i, j;
    for (i = 0; i < n; ++i)
        for (j = 0; j < 3180; ++j)
            ;
}

int decode(char msg)
{
  int data = 0x00;
  
  switch (msg)
  {
    case 'R':
        data = 0x02;
        break;
    case 'B':
        data = 0x04;
        break;
    case 'M':
        data = 0x06;
        break;
    case 'G':
        data = 0x08;
        break;
    case 'Y':
        data = 0x0A;
        break;
    case 'C':
        data = 0x0C;
        break;
    case 'W':
        data = 0x0E;
        break;
  }
  
  return data;
}

void spi_master_ini(void)
{
  SYSCTL_RCGCSSI_R |= (1 << 0);                                    // Enable clock on appr SSI Module
  SYSCTL_RCGCGPIO_R |= (1 << 0);                                   // Enable GPIO Clock on PORT A
  GPIO_PORTA_AFSEL_R |= (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5); // Select Alternate functions for pins PA2-PA5
  GPIO_PORTA_PCTL_R = 0x00222200;                                  // Set control register for pins PA2-PA5
  GPIO_PORTA_DEN_R |= (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);   // Enable digital on pins PA2-PA5
  GPIO_PORTA_PUR_R |= (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);   // Selecting pull up registers
  SSI0_CR1_R = 0;                                                  // Disable SSI Module while configuring
  SSI0_CC_R = 0;                                                   // Use the main system clock
  SSI0_CPSR_R = 64;                                                // Selecting divisor 64 for SSI Clock
  SSI0_CR0_R = 0x07;                                               // Set configuration of SSI - freescale mode, 8 bit data, steady low clock
  SSI0_CR1_R |= (1 << 1);                                          // Enable SPI
}

void spi_slave_ini(void)
{
  SYSCTL_RCGCSSI_R |= (1 << 2);                                    // Enable clock on appr SSI Module
  SYSCTL_RCGCGPIO_R |= (1 << 1);                                   // Enable GPIO Clock on PORT B
  GPIO_PORTB_AFSEL_R |= (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7); // Select Alternate functions for pins PB4-PB7
  GPIO_PORTB_PCTL_R = 0x22220000;                                  // Set control register for pins PB4-PB7
  GPIO_PORTB_DEN_R |= (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);   // Enable digital on pins PP4-PB7
  GPIO_PORTB_PUR_R |= (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);   // Selecting pull up registers
  SSI2_CR1_R = 0;                                                  // Disable SSI Module while configuring
  SSI2_CR0_R = 0x07;                                               // Set configuration of SSI - freescale mode, 8 bit data, steady low clock
  SSI2_CR1_R |= (1 << 1) | (1 << 2);                               // Enable SPI and set slave
}

int main()
{
  /* Configure the SPI Master Module - Module 0 */
  spi_master_ini();
  
  /* Configure the SPI Slave Module - Module 2 */
  spi_slave_ini();
  
  /* Configure UART Communication to read */
  SYSCTL_RCGCUART_R |= (1 << 0);                // Enable clock to UART0
  GPIO_PORTA_AFSEL_R |= (1 << 0) | (1 << 1);    // Enable Alternate functions in PA0 and PA1
  GPIO_PORTA_PCTL_R |= 0x00000001 | 0x00000010; // Set CTL for pins PA0 and PA1 as UART
  GPIO_PORTA_DEN_R |= (1 << 0) | (1 << 1);      // Enable DEN in PA0 and PA1
  
  UART0_CTL_R &= ~(1 << 0);                     // Disable UART by clearing UARTEN in CTL
  UART0_IBRD_R = 104;                           // Set BRD - integer portion
  UART0_FBRD_R = 11;                            // Set BRD - fractional portion
  UART0_LCRH_R = (0x3 << 5) | (1 << 4);         // Set line control settings - 8 bit, no parity, 1-stop bit
  UART0_CTL_R = (1 << 0) | (1 << 8) | (1 << 9); // Enable UART by setting UARTEN bit

  /* PORT F Config */
  SYSCTL_RCGCGPIO_R |= 0x20; // 0b100000 Enable Port F only
    
  GPIO_PORTF_DIR_R = 0xE; // 0b1110
    
  GPIO_PORTF_DEN_R = 0xE; // 0b1110
 
  // Define control variables
  char c;
  char msg[] = {'R', 'B', 'M', 'G', 'Y', 'C', 'W'};
  int index = 0;

  while (1)
  {
    /* Send the Control Message from SSI0 to SSI2 */
    c = msg[index];
    sendChar(c);    
    
    /* Sent message */
    printString("Sent Message from Master Module (SPI0 Module) : ");
    printChar(c);
    printString("\n\r");
    
    delayMs(100); // Delay for a while

    /* Read the message at SSI2 */
    c = recvChar();
    
    /* Light the LED with the color code correspoding to the recvd message */
    GPIO_PORTF_DATA_R = decode(c);
    
    delayMs(100); // Delay for a while

    /* Print the message received through UART on the terminal */
    printString("Received Message in Slave Module (SPI2 Module) : ");
    printChar(c);
    printString("\n\n\n\r");

    delayMs(2000); // Delay for a while

    /* Go onto the next control message index */
    index = (index + 1) % sizeof(msg);
  }
}