# Vectors

1. Is like a array but it doubles it's capacity as soon as size and capacity are equal.
2. library <vector>
3. push_back to insert elements in the vector
4. pop_back to pop elements in the vector 
5. vector.size() To get number of elements in the vector and vector.capacity() to get how much space do we have in vector.
6. v.resize(n) creates N buckets in vector.
7. If there are no buckets for vector we need to use push_back but if we define a size we can use it like a Array.
```
    vector <int> v;
    v.push_back(1); //[1]
    v.push_back(2); //[1,2]
    v.push_back(3); //[1,2,3]
    v.push_back(4);
    v.push_back(5);

    v.size(); // 5
    v.capacity(); //8

    v.pop_back(); //5
    v.pop_back(); //4

    v.resize(20); //Here N == 20
    v.capacity(); //20 
```