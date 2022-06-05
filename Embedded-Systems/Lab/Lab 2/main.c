#define RED 0x02U
#define BLUE 0x04U
#define GREEN 0x08U
#define MAGENTA 0x06U      // Red + Blue
#define CYAN 0x0CU         // Blue + Green
#define YELLOW 0x0AU       // Red + Green
#define WHITE 0x0EU        // Red + Blue + Green
#define LED_OFF 0x00U      // All LED's are switched off

#define BUTTON_PRESS 0x00U // Value when SW1 Button is pressed

#define BUTTON *((unsigned int *) 0x40025040) // Address of PF4 Switch 1

// Function to simulate SW1 button pressing
void simulate_button_press(int itr)
{
  // Button is pressed on every even iteration
  if(itr%2==0)
  {
    BUTTON=BUTTON_PRESS;   // Button is pressed
  }
  else
  {
    BUTTON=~BUTTON_PRESS;  // Button is not pressed
  }
}

int main()
{
  *((unsigned int *) 0x400FE608)=0x20U;          // Clock gating register to enable the clock on GPIO F port
  *((unsigned int *) 0x40025400)=0x0EU;          // Direction for input/output
  *((unsigned int *) 0x4002551C)=0x0EU;          // Digital function enabled on PF1,PF2,PF3 
  *((unsigned int *) 0x40025524)=0x10U;           // Set GPIOCR register for PF4 to allow write access (SW1 is connected to PF4 where Pull-up needs to be enabled)
  *((unsigned int *) 0x40025510)=0x10U;           // Enable Pull-Up Resistor for PF4
  *((unsigned int *) 0x40025520)=0x4C4F434BU;     // Unlocks GPIOCR register for write access
  
  int count=0;
  int itr=0;
  int colours[]={LED_OFF, RED, BLUE, GREEN, MAGENTA, CYAN, YELLOW, WHITE};
  *((unsigned int *) 0x400253FC)=colours[count];
  
  while(1)
  {
    simulate_button_press(itr);
    if(BUTTON==BUTTON_PRESS)
    {
      count=(count+1)%8;
      *((unsigned int *) 0x400253FC)=colours[count];
    }
    
    itr+=1;
  }
  
  return 0;
}
