# Linked List

1. Linked List is non continuous data structure.
2. Linked List is basically have a data member and a pointer where that data member will be pointing to.
3. Here the address for next member will be stored in next 
    - here the datatype of this data member of the node will be of type itself cause it is storing address of same bucket type.
    - Node is a self Referential class i.e a class that uses it self as a data member it is self referential class.
```
class node {
    int data;
    node * next;
}

node a;
a.data = 10;
a.next = NULL;
node b ; 
b.data = 20;
a.next = &b;
b.next = NULL;
```

4. Ways Access Data Of A Node
```
 //This is for getting data from b which is pointed by next of a
 b.data;
 (*a.next).data;
 a.next -> data;
```