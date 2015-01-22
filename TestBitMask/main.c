#include <stdio.h>
#include <stdlib.h>

#define bool unsigned char

//Forward declaration
//unsigned U2LGetViaString(unsigned int DUT, UnicodeString ucAddr);
bool BitMask( int iRead,  char cBit);


int main(int argc, char *argv[])
{
  printf("Hello World\n");  
  printf("(c) Keysolution A/S 2012\n");  
  system("PAUSE");	
  
  int iInner, iOuter;
  for (iOuter = 0; iOuter<10; iOuter++)
  {
    for (iInner = 0; iInner<300; iInner++)
    {
      printf("Inner\n");
//      system("PAUSE");        
    }
    printf("                                 Outer\n");  // STOPPER efte ca. 10 sekunder
    if (iOuter == 3)
    system("PAUSE\n");        
  }
  
  //Test BitMask:
  unsigned int iRead=0x0c; // 00001100
  unsigned char cBit=0x03; // 00001000
  // Result                       1     
  printf("Test output:");
  printf("iRead = %d\n", iRead);
  iRead = BitMask(iRead, cBit); //Mask result for the correct bit
  printf("iRead = %d\n", iRead);
  
  system("PAUSE\n");        
  
  return 0;
}






/**
\brief Utility function for masking bit
\param [in] iRead
\param [in] cBit
\return bRes is the mask result, true if bit is set
\author Carsten Mols
 */
bool BitMask( int iRead,  char cBit)
{
  unsigned char cMaskBit;
  bool bRes;

  cMaskBit = (1 << cBit); //Create mask bit
  bRes = ((unsigned char)(iRead & cMaskBit) == cMaskBit);

  return bRes; //true if bit set, else false
}



