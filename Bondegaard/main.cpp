#define MY_EXAMPLE
//#define FIGURER


#ifdef FIGURER 

#include <iostream> 
#include <string> 
using namespace std;
 
class BasePoint { 
public:
	BasePoint(int px, int py):x(px),y(py) {} 
	int x, y; //position 
	virtual string type() = 0;
	virtual void info() { 
		cout << endl << "figure: " << type() << endl;
		cout << "position: x=" << x << ", y=" << y << endl;
	} 
};
 
class Figure1P : public BasePoint { 
public:
	Figure1P(int px, int py, int r):p1(r),BasePoint(px, py) {} 
	int p1;
	virtual void info() { 
		BasePoint::info();
		cout << "property 1: p=" << p1 << endl;
	} 
};
 
class Square : public Figure1P { 
public:
	Square(int px, int py, int r):Figure1P(px, py, r) {};
	virtual string type() { 
		return "square";
	} 
};
 
class Circle : public Figure1P { 
public:
	Circle(int px, int py, int r):Figure1P(px, py, r) {} 
	virtual string type() { 
		return "circle";
	} 
};
 
class Figure2P : public Figure1P { 
public:
	Figure2P(int px, int py, int w, int h):p2(h),Figure1P(px, py, w) {} 
	int p2;
	virtual void info() { 
		Figure1P::info();
		cout << "property 2: p=" << p2 << endl;
	} 
};
 
class Rectangle : public Figure2P { 
public:
	Rectangle(int px, int py, int w, int h):Figure2P(px, py, w, h) {} 
	virtual string type() { 
		return "rectangle";
	} 
};
 
class Oval : public Figure2P { 
public:
	Oval(int px, int py, int w, int h):Figure2P(px, py, w, h) {};
	virtual string type() { 
		return "oval";
	} 
};
 
int main(void) { 
	BasePoint **objs = new BasePoint*[5]; 
	// allocate space for 10 BasePoint pointers,  
	// they may be used to store derived classes 
 
	// creating objects 
	objs[0] = new Circle(7, 6, 55);
	objs[1] = new Rectangle(12, 54, 21, 14);
	objs[2] = new Square(19, 32, 10);
	objs[3] = new Oval(43, 10, 4, 3);
	objs[4] = new Square(3, 41, 3);
 
	bool flag=false; 
	do { 
		cout << endl << "We have 5 objects with numbers 0..4" << endl;
		cout << "Enter object number to view information about it " << endl;
		cout << "Enter any other number to quit " << endl;
		char onum; // in fact, this is a character, not a number 
		// this allows user to enter letter and quit... 
		cin >> onum;
 
		// flag -- user have entered number 0..4 
		flag = ((onum >= '0')&&(onum <= '4'));
 
		if (flag) 
			objs[onum-'0']->info();
 
	} while(flag);
 
	// freeing memory 
	for(int i=0;i<5;i++) 
		delete objs[i];
 
	delete [] objs;
} 


#endif

































#ifdef MY_EXAMPLE

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/*
class Vehicle
{
//public void Accelerate(double kmH) {…}
//public double TopSpeed { get; set; }
}



// class Animal
// with two private fields name and age
// two public methods to retrieve fields (called "getters")
// and public non-default constructor
class Animal {
public:
  //Properties:
  Animal(string name, int age) 
  {
    this->name = name;
    this->age = age;
  }

  //Methods:
  string getName()
  {
    return name;
  }
  int getAge() 
  {
    return age;
  }

private:
  //Properties:
      string name;
      int age;
};

*/

      

void     ShowBondegaard()
{
//         class cDyr d;
//         d.dyr = 5;
         }
         
         
         



// class Person
// with two private fields name and age
// two public methods to retrieve fields (called "getters")
// and public non-default constructor
class Person {
public:
      
      Person(string name, int age) {
            this->name = name;
            this->age = age;
      }
      int Cpr()
      {
           //
      }
      string getName() {
            return name;
      }
      int getAge() {
            return age;
      }
private:
      string name;
      int age;
};


// class Mand (nedarvet fra Person)
class Mand :  public Person {
     public: 
     //Mand():Cpr() 
};

/*class Circle : public Figure1P { 
public:
	Circle(int px, int py, int r):Figure1P(px, py, r) {} 
	virtual string type() { 
		return "circle";
	} 
};
 */




int main(int argc, char *argv[])
{
    cout << "Hello C++ World" << "\n";
    
    ShowBondegaard();
    
      cout << "Creating a person..." << endl;
      Person johnDoe("John Doe", 25);
      cout << "Person's name: " << johnDoe.getName() << endl;
      cout << "Person's age: " << johnDoe.getAge() << endl;
 
  
    
    system("PAUSE");
    return EXIT_SUCCESS;
}





/*
#include <iostream>
#include <string>
 
using namespace std;
 
// class Person
// with two private fields name and age
// two public methods to retrieve fields (called "getters")
// and public non-default constructor
class Person {
public:
      Person(string name, int age) {
            this->name = name;
            this->age = age;
      }
      string getName() {
            return name;
      }
      int getAge() {
            return age;
      }
private:
      string name;
      int age;
};
 
int main() {
      cout << "Creating a person..." << endl;
      Person johnDoe("John Doe", 25);
      cout << "Person's name: " << johnDoe.getName() << endl;
      cout << "Person's age: " << johnDoe.getAge() << endl;
 
      return 0;
}
 */
 
#endif
