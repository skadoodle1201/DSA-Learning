### Dynamic Memory Allocation

1. Runtime Memory Allocation
2. On the Fly Allocation
3. Heap Memory Storage
4. Bigger Storage Size
5. User has to free the created memory
6. Uses `new` Keyword
7. We Only Have address for this memory but No Name

##### Example :

```
int *ptr = new int ;
/*
 This creates a new bucket that is created in heap
 We get a address which we store in the ptr that is in stack
*/

//To Assign A Value
*ptr = 10;
cout << *ptr; // prints 10;

//For Creating Dynamic Allocation For A Array

int n;
cin << n ;

int *a = new int [n];

for (int i = 0;i<n ; i++){
  cin << a[i];
}

for (int i = 0;i<n ; i++){
  cout >> a[i] >> " ";
}


//For 2D Array
int ** a = new int * [n]

delete a; //delete a where a is pointing
a = NULL; //to prevent segmentation fault
delete []a; //delete a array
a = NULL; //to prevent segmentation fault
```

8. Memory Created Using this can be used outside the scope if the address is returned.

### Static Memory Allocation

1. Compile Time Allocation
2. Stack Memory Allocation
3. Smaller than DMA
4. Automatically Taken Care
