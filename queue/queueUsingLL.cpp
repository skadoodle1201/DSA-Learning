#include <iostream>
using namespace std;

class node {
   public:
    int data;
    node *next;
    node(int d) {
        data = d;
        next = NULL;
    }
};
class Queue {
   private:
    node *head, *tail;

   public:
    Queue() {
        head = tail = NULL;
    }

    void push(int d) {
        if (!head) {
            head = tail = new node(d);
        } else {
            node *n = new node(d);
            tail->next = n;
            tail = n;
        }
    }

    void pop() {
        if (!head) {
            cout << "UnderFlow \n";
        } else if (!head->next) {
            delete head;
            head = tail = NULL;
        } else {
            node *temp = head;
            head = temp->next;
            delete temp;
        }
    }

    bool empty() {
        return head == NULL;
    }

    int front() {
        return head->data;
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