// classes example

#include <iostream>

using namespace std;


class CRectangle {
    int x, y;
  public:
    void set_values (int,int);
    int area () {return (x*y);}
    int circuit () {return (2*x+2*y);}
    float relation () {return ((float)x/y);}
};


class Car
{
  public:
    //basic constructor 
    Car(){};
     //methods of class car 
    int accelerate(int gears);
    int stop(int gear);
    void printInfo(Car crobj);
    //data elements 

    int year;

  private:
    int speed;
    string name;
};


//defining methods
int Car::accelerate(int gear)
{
  gear = 6;
  return gear;
}


int Car::stop(int gear)
{
  gear = 0;
  return gear;
}


void Car::printInfo(Car crobj)
{
  cout<<"Manufacturer:\t"<<crobj.name<<"Build Year:\t"<<crobj.year<<endl;
}


void CRectangle::set_values (int a, int b) {
  x = a;
  y = b;
}



int main (int argc, char *argv[])
{



  // 
  // Test using CRectangle class
  //
  CRectangle  r;
  printf("Dette er en test \n");
  const int x=3, y=4;	//Test stimuli data
  r.set_values(x,y);
  printf("Input %d, %d => Area =%d\n", x, y,r.area());
  printf("Realtion is =%f\n", r.relation());
  printf("\n\n\n");
  std::cout << "Press any key ...\n";
  std::cin.get();

  // 
  // Test Car
  //
  printf("Car test - not implemented yet ...\n");
  printf("\n\n\n");
  std::cout << "Press any key ...\n";
  std::cin.get();


  // Stand-alone test
  // Check position check code OK ...
  //
  int iPosNow = 94;
  int iPosVerify = 96;

  if((iPosVerify <= (iPosNow+1)) && (iPosVerify >= (iPosNow-1))) //Err if more than +- 1 mm
 {
    //OK
    printf("OK inden for range.\n");
  }
  else
  {
    //Fejl
    printf("Fejl\n");
  }


  // Stand-alone test
  // Test MSB+LSB adding
  //
  int iAnsLsb = 18596; //Adr for actuator PO number lower
  int iAnsMsb = 28; //Adr for actuator PO number upper
  int iPosition = ((iAnsMsb<<16) + iAnsLsb);
      printf("PO is %u\n", iPosition);
  iPosition = ((iAnsMsb*65536) + iAnsLsb);
      printf("PO is %u\n", iPosition);
      printf("Mojn!\n");
  

}

