#include <iostream>
using namespace std;

void permutation(char *a, int i)
{
    // base case
    if (a[i] == '\0')
    {
        cout << a << endl;
        return;
    }
    // recursive case
    for (int j = i; a[j] != '\0'; ++j)
    {
        swap(a[i], a[j]);
        permutation(a, i + 1);
        swap(a[i], a[j]); // Backtracking
    }
}

int main()
{
    int row, col;
    cin >> row;
    cin >> col;
    char *sol = new char[row + col - 2];
    for (int i = 0; i < row; i++)
    {
        sol[i] = 'H';
    }

    for (int i = 0; i < row; i++)
    {
        sol[i] = 'V';
    }

    permutation(sol, 0);
    return 0;
}