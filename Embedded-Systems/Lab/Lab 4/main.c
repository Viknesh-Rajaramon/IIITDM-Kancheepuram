#include <time.h>

void delay(float seconds)
{
  float milli_seconds=10*seconds;
  clock_t start_time=clock();
  while(clock()<(start_time+milli_seconds));
}

int main()
{
  (*((volatile unsigned long *) 0x400FE608))=0x04; // Clock gating register to enable the clock on GPIO Port C
  (*((volatile unsigned long *) 0x40006400))=0xF0;  // Data Direction
  (*((volatile unsigned long *) 0x4000651C))=0xF0;  // Digital Enable
  
  int values[]={0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0};
  int count=0;

  while (1)
  {
    (*((volatile unsigned long *) 0x400063FC))=values[count];
    count=(count+1)%16;
    delay(10);
  }
  
  return 0;
}