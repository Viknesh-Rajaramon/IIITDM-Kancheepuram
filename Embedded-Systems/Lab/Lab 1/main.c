
int main()
{
  *((unsigned int *) 0x400FE608)=0x20U; // Clock gating register to enable the clock on GPIO F port
  *((unsigned int *) 0x40025400)=0x0EU; // Direction for input/output
  *((unsigned int *) 0x4002551C)=0x0EU; // Digital function enabled on PF1,PF2,PF3
  
  int delay_1sec=1000000; // Approximate no. of iterations for 1 second delay - Simulation clock runs at 1MHz
  
  while(1)
  {
    // Data register of Port F (Red LED address)
    *((unsigned int *) 0x40025008)=0x2U;
    for(int i=0;i<=1*delay_1sec;++i); // 1 second delay
    *((unsigned int *) 0x40025008)=0x00U;
    
    // Data register of Port F (Green LED address)
    *((unsigned int *) 0x40025010)=0x04U;
    for(int i=0;i<=2*delay_1sec;++i);// 2 second delay
    *((unsigned int *) 0x40025010)=0x00U;
    
    // Data register of Port F (Blue LED address)
    *((unsigned int *) 0x40025020)=0x08U;
    for(int i=0;i<=3*delay_1sec;++i);// 3 second delay
    *((unsigned int *) 0x40025020)=0x00U;
  }
  
  return 0;
}
