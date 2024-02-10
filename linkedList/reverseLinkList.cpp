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

void deleteFromStart(node *&head, node *&tail) {
    if (!head) {
        return;
    }
    if (!head->next) {
        delete head;
        head = tail = NULL;
        return;
    }
    node *nodeAtHead = head;

    head = head->next;
    delete nodeAtHead;
}

void deleteFromEnd(node *&head, node *tail) {
    if (!head) {
        return;
    }
    if (!head->next) {
        delete head;
        head = tail = NULL;
        return;
    }
    node *nodeAtSecondLast = head;
    while (nodeAtSecondLast->next != tail) {
        nodeAtSecondLast = nodeAtSecondLast->next;
    }
    delete tail;
    tail = nodeAtSecondLast;
    tail->next = NULL;
}

void deleteAtNPos(node *&head, node *&tail, int pos) {
    if (pos == 0) {
        return deleteFromStart(head, tail);
    }
    if (pos >= lengthLL(head) - 1) {
        return deleteFromEnd(head, tail);
    }
    node *nodeAtNthPos = head;
    for (int i = 1; i < pos - 1; i++) {
        nodeAtNthPos = nodeAtNthPos->next;
    }
    node *toDelete = nodeAtNthPos->next;
    nodeAtNthPos->next = toDelete->next;
    delete toDelete;
}

node *searchInLL(node *head, int key) {
    if (!head) return NULL;
    if (head->data == key) {
        return head;
    }
    return searchInLL(head->next, key);
}

void reverseLL(node *&head, node *&tail) {
    node *curr = head;
    node *prev = NULL;
    node *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    swap(head, tail);
}

void reverseLLwithRecursion(node *&head, node *&tail, node *curr, node *prev) {
    if (curr == NULL) {
        swap(head, tail);
        return;
    }

    node *next = curr->next;
    curr->next = prev;

    reverseLLwithRecursion(head, tail, next, curr);
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

    insertAtStart(head, tail, 7);
    insertAtStart(head, tail, 8);
    insertAtStart(head, tail, 9);
    printLL(head);

    cout << "Search In Linked List Found :: " << searchInLL(head, 8)->data << endl;

    reverseLL(head, tail);
    printLL(head);
    reverseLLwithRecursion(head, tail, head, NULL);
    printLL(head);

    return 0;
}