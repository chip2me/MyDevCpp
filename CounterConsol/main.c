#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{
  printf("Hello World\n");  
  printf("(c) Keysolution A/S 2012\n");  
  system("PAUSE");	
  
  int iInner, iOuter;
  for (iOuter = 0; iOuter<10; iOuter++)
  {
    for (iInner = 0; iInner<30000; iInner++)
    {
      printf("Inner\n");
//      system("PAUSE");        
    }
    printf("                                             Outer\n");  // STOPPER efte ca. 10 sekunder
    if (iOuter == 3)
    system("PAUSE");        
  }
  return 0;
}




