#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int i = 1;
  while (i <= n) {
    for (int j = 0; j < i; j++) {
      if (i == 0 or i == 1) {
        cout << 1;
      } else {
        if (j == 0 or j == i - 1) {
          cout << i - 1;
        } else {
          cout << 0;
        }
      }
    }

    i++;
    cout << endl;
  }
  return 0;
}
