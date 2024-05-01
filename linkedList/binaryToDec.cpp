#include <cmath>
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

void addAtEnd(int d, node *&head, node *&tail) {
  node *nh = new node(d);
  if (!head) {
    head = tail = nh;
  } else {
    tail->next = nh;
    tail = nh;
  }
}
int convertToDec(node *head) {
  node *curr, *next, *prev = NULL;
  curr = head;
  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  //   cout << prev->data;

  int dec = 0;
  int count = 0;
  while (prev) {
    dec += prev->data * pow(2, count);
    prev = prev->next;
    count++;
  }
  return dec;
}
int main() {
  int n;
  cin >> n;
  node *head, *tail;
  head = tail = NULL;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    addAtEnd(d, head, tail);
  }

  int dec = convertToDec(head);
  cout << dec;
  return 0;
}
