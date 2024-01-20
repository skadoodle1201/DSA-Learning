#include <iostream>
using namespace std;

void subsequences(char *inp, int i, char *out, int j)
{
  if (inp[i] == '\0')
  {
    out[j] = '\0';
    cout << out << endl;
    return;
  }

  // 1. Ignore the ith Char and pass the new string
  subsequences(inp, i + 1, out, j);

  // 2. Inlcude the ith Char copy it to Out String
  out[j] = inp[i];
  subsequences(inp, i + 1, out, j + 1);
}

int main()
{
  char inp[] = "abc";
  char out[100];
  subsequences(inp, 0, out, 0);
  return 0;
}