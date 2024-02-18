#include <iostream>
#include <stack>

using namespace std;

void insertElementAtBottom(stack<int> &s, int topElement) {
    if (s.empty()) {
        s.push(topElement);
        return;
    }

    int top = s.top();
    s.pop();
    insertElementAtBottom(s, topElement);
    s.push(top);
}

void reverseStack(stack<int> &s) {
    if (s.empty()) {
        return;
    }

    int topElement = s.top();
    s.pop();
    reverseStack(s);
    insertElementAtBottom(s, topElement);
}
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;
}
int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    printStack(s);
    reverseStack(s);
    printStack(s);
    return 0;
}