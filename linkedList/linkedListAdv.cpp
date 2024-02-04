#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertAtStart(node *&head, node *&tail, int value)
{
    node *newNode = new node(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void insertAtEnd(node *&head, node *&tail, int value)
{
    node *newNode = new node(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void printLL(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " --> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    /* Creating A Linked List
     */

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

    return 0;
}