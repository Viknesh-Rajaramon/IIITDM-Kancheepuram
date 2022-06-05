#define RED 0x02U
#define BLUE 0x04U
#define GREEN 0x08U
#define LED_OFF 0x00U      // All LED's are switched off

#define BUTTON_PRESS 0x00U // Value when SW1 or SW2 Button is pressed

#define LEFT_BUTTON *((unsigned int *) 0x40025040) // Address of PF4 Switch 1
#define RIGHT_BUTTON *((unsigned int *) 0x40025004) // Address of PF0 Switch 2

// Function to simulate SW1 and SW2 button pressing
void simulate_button_press(int itr)
{
  if(itr%4==0)  // All LED's are off
  {
    RIGHT_BUTTON=~BUTTON_PRESS;   //SW2 Button is not pressed
    LEFT_BUTTON=~BUTTON_PRESS;    //SW1 Button is not pressed
  }
  else if(itr%4==1)  // Red LED glows
  {
    RIGHT_BUTTON=~BUTTON_PRESS;   //SW2 Button is not pressed
    LEFT_BUTTON=BUTTON_PRESS;     //SW1 Button is pressed
  }
  else if(itr%4==2)  // Blue LED glows
  {
    RIGHT_BUTTON=BUTTON_PRESS;    //SW2 Button is pressed
    LEFT_BUTTON=~BUTTON_PRESS;    //SW1 Button is not pressed
  }
  else  // Green LED glows
  {
    RIGHT_BUTTON=BUTTON_PRESS;    //SW2 Button is pressed
    LEFT_BUTTON=BUTTON_PRESS;     //SW1 Button is pressed
  }
}

int main()
{
  *((unsigned int *) 0x400FE608)=0x20U;           // Clock gating register to enable the clock on GPIO F port
  *((unsigned int *) 0x40025400)=0x0EU;           // Direction for input/output
  *((unsigned int *) 0x4002551C)=0x0EU;           // Digital function enabled on PF1,PF2,PF3 
  *((unsigned int *) 0x40025524)=0x11U;           // Set GPIOCR register for PF4 and PF0 to allow write access (SW1 is connected to PF4 and SW2 is connected to PF0 where Pull-up needs to be enabled)
  *((unsigned int *) 0x40025510)=0x11U;           // Enable Pull-Up Resistor for PF4 and PF0
  *((unsigned int *) 0x40025520)=0x4C4F434BU;     // Unlocks GPIOCR register for write access
  
  int count=0;
  int itr=0;
  int colours[]={LED_OFF, RED, BLUE, GREEN};
  
  while(1)
  {
    simulate_button_press(itr);
    count=itr%4;
    *((unsigned int *) 0x400253FC)=colours[count];    
    itr+=1;
  }
  
  return 0;
}