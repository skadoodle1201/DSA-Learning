#include <iostream>

using namespace std;

class Vector
{
private:
    int *a;
    int maxSize;
    int curSize;

public:
    Vector(int s = 2)
    {
        a = new int[s];
        maxSize = 2;
        curSize = 0;
    }

    void push_back(int d)
    {
        if (curSize == maxSize)
        {
            // Double the size of vector
            int *newVector = new int[maxSize * 2];
            for (int i = 0; i < curSize; i++)
            {
                newVector[i] = a[i];
            }
            delete[] a;
            a = newVector;
            maxSize *= 2;
        }
        a[curSize] = d;
        curSize++;
    }

    void pop_back()
    {
        if (curSize > 0)
        {
            curSize--;
        }
    }

    int size()
    {
        return curSize;
    }

    int capacity()
    {
        return maxSize;
    }

    int operator[](int index)
    {
        return a[index];
    }

    void print()
    {
        for (int i = 0; i < curSize; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    Vector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout << "Elemtent at index 2: " << v[2] << " Size: " << v.size() << " Capacity: " << v.capacity() << endl;
    v.pop_back();
    v.print();
    return 0;
}