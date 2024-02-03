#include <iostream>
#include <cstring>
using namespace std;

/* Teaches How to Use Dynamic Memory Allocation for efficient Memory use
 *
 */

class car
{
public:
    char *name; // Assigned A Garbage Address
    int price;
    int model;
    int seats;

    car(char *n, int p, int m, int s)
    {
        name = NULL;                    // Make the Garbage Value To Null
        name = new char[strlen(n) + 1]; // Allocating Memory to the char for string and adding a valid address
        strcpy(name, n);
        price = p;
        model = m;
        seats = s;
    }

    void setName(char *n)
    {
        if (name != NULL)
        {
            delete[] name;
        }
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    void print()
    {
        cout << name << '\t' << model << '\t' << price << '\t' << seats << endl;
    }
    ~car()
    {
        delete[] name;
        name = NULL;
    }
};
int main()
{
    car c1("AUDI", 10, 20, 3);
    c1.print();

    c1.setName("MARUTI");
    c1.print();
    return 0;
}