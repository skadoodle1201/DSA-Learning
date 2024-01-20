#include <iostream>
using namespace std;

/*
1. Call Helper and des are swapped
3. Manual Print
2. Call Src and Helper are Swapped
*/
void toh(int n, char src, char helper, char des)
{
  // base Case
  if (n == 0)
  {
    return;
  }

  // n-1 to help (recursion)
  toh(n - 1, src, des, helper);
  // manuall last or largest disk
  cout << "Take " << n << " From " << src << " To " << des << endl;

  // n-1 from help to des (rercuresion)
  toh(n - 1, helper, src, des);
}

int main()
{
  toh(3, 'A', 'B', 'C');
  return 0;
}