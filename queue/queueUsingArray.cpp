#include <iostream>
using namespace std;

/*
    This is A Circular Queue Implementation
*/

class Queue {
   private:
    int *a;
    int n;
    int cs;
    int f, e;

   public:
    Queue(int size = 5) {
        a = new int[size];
        n = size;
        f = cs = 0;
        e = n - 1;
    }

    void push(int d) {
        if (cs == n) {
            cout << "Queue OverFlow \n";
            return;
        }
        e = (e + 1) % n;
        a[e] = d;
        cs++;
    }

    void pop() {
        if (cs <= 0) {
            cout << "Queue UnderFlow \n";
            return;
        }
        f = (f + 1) % n;
        cs--;
    }

    bool empty() {
        return cs == 0;
    }

    int front() {
        return a[f];
    }
};

int main() {
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(7);
    q.pop();
    q.pop();
    q.pop();
    q.push(6);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    q.pop();
    return 0;
}