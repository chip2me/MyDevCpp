// classes example
#include <iostream>
using namespace std;

class CRectangle {
    int x, y;
  public:
    void set_values (int,int);
    int area () {return (x*y);}
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



int main () {

static int iCounter;

while (true)
{
      if (iCounter % 10 == 0)
printf("Dette er en test %d\n", iCounter);
if (iCounter > 1000)
break;
iCounter++;
}














  CRectangle rect;
  rect.set_values (3,4);
  cout << "area: " << rect.area();

  cout << "\n\n";
  
  Car myCar1, myCar2;
  myCar1.accelerate(3);
  myCar1.stop(0);
  myCar1.year = 2011;

  myCar2.accelerate(3);
  myCar2.stop(0);
  myCar2.year = 2010;

  myCar1.printInfo(myCar1);
  myCar1.printInfo(myCar2);
  myCar1.printInfo(myCar1);
  myCar1.printInfo(myCar2);
  myCar1.printInfo(myCar1);


  cout << "\n\n";
  system("PAUSE");
  return EXIT_SUCCESS;
}





