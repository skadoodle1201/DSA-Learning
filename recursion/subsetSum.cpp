#include <iostream>

using namespace std;

void subSetSum(char *number, int target, int sum, char *subSet, int i, int j, int &count, int n)
{
    // base case
    if (sum == target)
    {
        for (int i = 0; subSet[i] != '\0'; i++)
        {
            cout << subSet[i] << " ";
        }
        cout << " ";
        count++;
        return;
    }
    if (i == n)
    {
        return;
    }

    subSet[j] = number[i];
    subSetSum(number, target, sum + (number[i] - '0'), subSet, i + 1, j + 1, count, n);
    subSet[j] = '\0';

    subSetSum(number, target, sum, subSet, i + 1, j, count, n);
}
int main()
{

    int n;
    cin >> n;
    char number[1000000];
    for (int i = 0; i < n; i++)
    {
        cin >> number[i];
    }
    int target;
    cin >> target;

    char subSet[1000000];
    int count = 0;

    subSetSum(number, target, 0, subSet, 0, 0, count, n);
    cout << endl
         << count;
    return 0;
}