#include <iostream>
using namespace std;

void mergeArray(int *a, int *b, int *c, int s, int e)
{
  int mid = (s + e) / 2;
  int i = s, j = mid + 1;
  while ()
}

void mergeSort(int *inp, int s, int e)
{

  if (s >= e)
  {
    return;
  }

  int b[10000], c[10000];
  int mid = (s + e) / 2;
  for (int i = 0; i <= mid; i++)
  {
    b[i] = inp[i];
  }

  for (int i = mid + 1; i <= e; i++)
  {
    c[i] = inp[i];
  }

  mergeSort(b, s, mid);
  mergeSort(c, mid + 1, e);

  mergeArray(inp, b, c, s, e)
}