#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void nextGreater(vector<int> v, int n) {
  vector<int> res(n);
  stack<int> s;

  for (int i = n - 1; i >= 0; i--) {
    while (!s.empty() and v[i] >= v[s.top()]) {
      s.pop();
    }
    res[i] = (s.empty() ? -1 : v[s.top()]);
    s.push(i);
  }

  for (int i = 0; i < res.size(); i++) {
    cout << v[i] << ", " << res[i] << endl;
  }
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    nextGreater(arr, n);
  }

  return 0;
}
