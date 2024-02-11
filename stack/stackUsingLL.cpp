#include <iostream>

using namespace std;

template <typename T>
class node {
   public:
    node<T>* next;
    T data;

    node(T d) {
        data = d;
        next = NULL;
    }
};

template <typename T>
class Stack {
   private:
    node<T>* head;

   public:
    Stack() {
        head = NULL;
    }

    void push(T d) {
        if (head == NULL) {
            head = new node<T>(d);
        } else {
            node<T>* n = new node<T>(d);
            n->next = head;
            head = n;
        }
    }
    void pop() {
        if (!head->next) {
            delete head;
            head = NULL;
            return;
        }
        node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    T top() {
        return head->data;
    }

    bool empty() {
        return head == NULL;
    }
};
int main() {
    Stack<char> s;
    s.push('A');
    s.push('B');
    s.push('C');
    s.push('D');

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

    Stack<int> sInt;
    sInt.push(1);
    sInt.push(2);
    sInt.push(3);
    sInt.push(4);

    while (!sInt.empty()) {
        cout << sInt.top() << " ";
        sInt.pop();
    }

    return 0;
}