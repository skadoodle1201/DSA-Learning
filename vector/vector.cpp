#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);

    v.pop_back();

    cout << v.size() << endl;
    cout << v.capacity() << endl;

    /* To use vector as a array we need to set a capacity in starting using resize
     */
    vector<int> vAsArray;

    vAsArray.resize(10);

    for (int i = 0; i < 10; i++)
    {
        vAsArray[i] = i;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << vAsArray[i] << " ";
    }

    cout << endl;

    /* We can intialize a vector in starting
     */
    int n;
    cin >> n;
    vector<int> vIntialize(n);

    for (int i = 0; i < n; i++)
    {
        vIntialize[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        cout << vIntialize[i] << " ";
    }
    cout << endl;

    int value = 8;
    vector<int> vdefaultValue(10, value);

    for (int i = 0; i < vdefaultValue.size(); i++)
    {
        cout << vdefaultValue[i] << " ";
    }
    cout << endl;

    vector<int> vectorV = {1, 2, 3, 4, 5};
    for (int i = 0; i < vectorV.size(); i++)
    {
        cout << vectorV[i] << " ";
    }
    cout << endl;
    return 0;
}