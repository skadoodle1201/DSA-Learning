#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

int main()
{
    node a;
    node b;

    a.data = 1;
    a.next = &b;
    b.data = 2;
    b.next = NULL;

    cout << a.data << "-->" << b.data << "-->"
         << "NULL" << endl;
    cout << a.data << " --> " << (*a.next).data << " --> "
         << "NULL" << endl;

    cout << a.data << " --> " << a.next->data << " --> "
         << "NULL"
         << " With Arrow Operator" << endl;

    return 0;
}