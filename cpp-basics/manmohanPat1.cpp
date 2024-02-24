#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int i = 1;
  while (i <= n) {
    for (int j = 0; j < i; j++) {
      if (j == 0 or j == i - 1) {
        cout << 1;
      } else {
        if (i % 2 == 0) {
          cout << 0;
        } else {
          cout << 1;
        }
      }
    }

    i++;
    cout << endl;
  }
  return 0;
}
