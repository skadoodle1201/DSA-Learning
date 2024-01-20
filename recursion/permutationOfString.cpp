#include <iostream>
using namespace std;

void permutionsOfString(char *inp, int i)
{
  // base case
  if (inp[i] == '\0')
  {
    cout << inp << endl;
    return;
  }

  for (int j = i; inp[j] != '\0'; j++)
  {
    swap(inp[i], inp[j]);
    permutionsOfString(inp, i + 1);
    swap(inp[i], inp[j]); // Backtracking
  }
}

int main()
{
  char inp[] = "abc";
  permutionsOfString(inp, 0);
  return 0;
}