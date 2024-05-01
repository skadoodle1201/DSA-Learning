#include <iostream>
using namespace std;
bool check(int a[], int n) {

  // count number of push operations
  int ones = 0;

  // traverse in the array
  for (int i = 0; i < n; i++) {

    // push operation
    if (a[i])
      ones++;

    // pop operation
    else
      ones--;

    // if at any moment pop() operations
    // exceeds the number of push operations
    if (ones < 0)
      return false;
  }

  return true;
}
int main() {
  int t;
  cin >> t;
  while (t) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    if (check(arr, n)) {
      cout << "Valid" << endl;
    } else {
      cout << "Invalid" << endl;
    }
    t--;
  }

  return 0;
}
