#include <iostream>
using namespace std;

int reverse(int num) {
  int ans = 0;
  while (num != 0) {
    int rem = num % 10;
    ans = ans * 10 + rem;
    num = num / 10;
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int ans = reverse(reverse(a) + reverse(b));
    cout << ans << "\n";
  }
  return 0;
}
