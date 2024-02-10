#include <iostream>
using namespace std;

void mazepath(int i, int j, int n, int m, char sol[], int solLen, int &count)
{
    // base case
    if (i == n - 1 and j == m - 1)
    {
        cout << sol << " ";
        count++;
        return;
    }
    // recursive case
    if (j < m - 1)
    {
        sol[solLen] = 'H';
        mazepath(i, j + 1, n, m, sol, solLen + 1, count);
    }
    if (i < n - 1)
    {
        sol[solLen] = 'V';
        mazepath(i + 1, j, n, m, sol, solLen + 1, count);
    }
    if (i < n - 1 and j < m - 1)
    {
        sol[solLen] = 'D';
        mazepath(i + 1, j + 1, n, m, sol, solLen + 1, count);
    }
}

int main()
{
    int n, m;
    n = m = 3;
    char sol[1000];
    int count = 0;
    mazepath(0, 0, n, m, sol, 0, count);
    cout << endl
         << count;
    return 0;
}