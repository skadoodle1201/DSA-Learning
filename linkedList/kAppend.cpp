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

void printLL(node *head) {
  while (head) {
    cout << head->data << " ";
    head = head->next;
  }
}

void moveToFront(node *&head, node *&tail, int k) {
  if (head == NULL || head->next == NULL || k == 0) {
    return;
  }
  node *s = head;
  node *f = head;
  for (int i = 0; i < k; i++) {
    f = f->next;
  }
  while (f->next != NULL) {
    f = f->next;
    s = s->next;
  }
  tail->next = head;
  tail = s;
  head = s->next;
  s->next = NULL;
}

int main() {
  int n;
  cin >> n;
  node *head, *tail;
  head = tail = NULL;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    insertAtEnd(d, head, tail);
  }
  int k;
  cin >> k;
  if (k >= n) {
    k = k % n;
  }
  moveToFront(head, tail, k);

  printLL(head);
  return 0;
}
