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

int lengthLL(node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void insertAtEnd(node *&head, node *&tail, int value) {
    node *newNode = new node(value);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertInNpos(node *&head, node *&tail, int value, int pos) {
    if (pos == 0) {
        return insertAtStart(head, tail, value);
    }

    if (pos >= lengthLL(head)) {
        return insertAtEnd(head, tail, value);
    }

    node *n = new node(value);
    node *nodeAtn = head;
    for (int i = 0; i <= pos; i++) {
        nodeAtn = head->next;
    }
    n->next = nodeAtn->next;
    nodeAtn->next = n;
}

void printLL(node *head) {
    while (head != NULL) {
        cout << head->data << " --> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void bubbleSort(node *&head, node *&tail) {
    node *c, *p, *n;

    int len = lengthLL(head);
    for (int i = 0; i < len - 1; i++) {
        c = head;
        p = NULL;
        while (c and c->next) {
            n = c->next;
            if (c->data > n->data) {
                if (p == NULL) {
                    c->next = n->next;
                    n->next = c;
                    p = head = n;
                } else {
                    if (n == tail) {
                        tail = c;
                    }
                    c->next = n->next;
                    n->next = c;
                    p->next = n;
                    p = n;
                }
            } else {
                p = c;
                c = n;
            }
        }
    }
}

int main() {
    node *head = NULL, *tail = NULL;

    insertAtStart(head, tail, 10);

    insertAtEnd(head, tail, 1);
    insertAtEnd(head, tail, 2);
    insertAtEnd(head, tail, 3);
    insertAtEnd(head, tail, 4);
    insertAtEnd(head, tail, 5);
    insertAtEnd(head, tail, 6);

    insertAtEnd(head, tail, 7);
    insertAtStart(head, tail, 8);
    insertAtStart(head, tail, 9);

    printLL(head);
    bubbleSort(head, tail);
    printLL(head);

    return 0;
}