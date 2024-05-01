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
void insertAtStart(node *&head, node *&tail, int value) {
    node *newNode = new node(value);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void insertAtEnd(int data, node *&head, node *&tail) {
  node *newNode = new node(data);
  if (head == NULL) {
    head = tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
  return;
}

node *reveseK(node *head) {
  if (!head) {
    return head;
  }

  node *next, *curr, *prev;
  prev = next = NULL;
  curr = head;
  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}
void printLL(node *head) {
  while (head) {
    cout << head->data << " ";
    head = head->next;
  }
}

node *sumOfList(node *nh, node *nh2) {
  int carry = 0;
  node *sumH, *sumT;
  sumH = sumT = NULL;

  while (nh || nh2) {
    int sum = 0;
    if (nh) {
      sum += nh->data;
      nh = nh->next;
    }
    if (nh2) {
      sum += nh2->data;
      nh2 = nh2->next;
    }
    sum += carry;
    if (carry == 1)
      carry = 0;
    if (sum > 9) {
      carry = 1;
      sum = sum % 10;
    }
    insertAtStart(sumH, sumT, sum);
  }
  if(carry){
      insertAtStart(sumH, sumT,carry);
  }
  return sumH;
}

int main() {
  int n, n2;
  cin >> n >> n2;
  node *head, *tail;
  node *h2, *t2;
  head = h2 = tail = t2 = NULL;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    insertAtEnd(d, head, tail);
  }

  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    insertAtEnd(d, h2, t2);
  }

  node *nh = reveseK(head);
  node *nh2 = reveseK(h2);
  node *sumHead = sumOfList(nh, nh2);

  printLL(sumHead);
  return 0;
}
