#include <iostream>
#include <cstring>
using namespace std;

class car
{
public:
  char name[100];
  int price;
  int model;
  int seats;

  void print()
  {
    cout << name << '\t' << model << '\t' << price << '\t' << seats << endl;
  }
};
int main()
{
  car c1;

  /*
   * Otherwise we need to loop and add charaters one by one
   *
   *
   */
  strcpy(c1.name, "BMW"); // Copy One String to another
  c1.model = 2014;
  c1.price = 100;
  c1.seats = 4;

  car c2;

  strcpy(c2.name, "Maruti");
  c2.model = 2020;
  c2.price = 200;
  c2.seats = 10;

  c1.print();
  c2.print();

  // Creating Car Dynamically
  car *c = new car;

  strcpy((*c).name, "Audi");
  (*c).model = 2021;
  (*c).price = 100;
  (*c).seats = 2;

  (*c).print();

  delete c;
  c = NULL;

  return 0;
}