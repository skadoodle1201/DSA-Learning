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

node * reveseK(node *head, int n ){
    if(!head){
        return head;
    }

    node * next, * curr , * prev;
    prev = next = NULL;
    curr = head;
    int k = 0;
    while(curr and k < n){
        next = curr -> next;
        curr->next = prev;
        prev = curr;
        curr = next;
        k++;
    }

    if(next!=NULL)
        head->next = reveseK(next, n);
    return prev;

}
void printLL(node *head) {
  while (head) {
    cout << head->data << " ";
    head = head->next;
  }
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
  node *nh = reveseK(head, k);

  printLL(nh);
  return 0;
}
