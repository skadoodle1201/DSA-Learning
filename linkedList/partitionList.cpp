#include <iostream>
#include <sys/wait.h>

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

node *partitionK(node *head, int k) {
  if (head == NULL) {
    return head;
  }

  node *sh = NULL, *st = NULL;
  node *gh = NULL, *gt = NULL;
  node *eh = NULL, *et = NULL;

  while (head) {
    if (head->data < k) {
      if (sh == NULL) {
        sh = st = head;
      } else {
        st->next = head;
        st = head;
      }
    } else if (head->data == k) {
      if (eh == NULL) {
        eh = et = head;
      } else {
        et->next = head;
        et = head;
      }
    } else if (head->data > k) {
      if (gh == NULL) {
        gh = gt = head;
      } else {
        gt->next = head;
        gt = head;
      }
    }
    head = head->next;
  }

  node *nh = NULL, *nt = NULL;
  if(sh != NULL){
      nh = sh;
      st->next = eh;

      if(st->next != NULL and et != NULL) et->next = gh;
      else st->next = gh;
  }else {
      if(sh == NULL){
          nh = eh;
          et->next = gh;

          if(et->next != NULL and et != NULL) et->next = gh;
          else st->next = gh;
      }
  }
}
void printLL(node *head) {
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  node *head, *tail;
  head = tail = NULL;

  int l1;
  cin >> l1;
  for (int i = 0; i < l1; i++) {
    int d;
    cin >> d;
    insertAtEnd(d, head, tail);
  }

  int k;
  if (k < l1) {
    moveNodeFromKToFront(k, head);
  }
  printLL(head);
  return 0;
}
