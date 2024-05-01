#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int area(vector<int> v, int n) {
  vector<int> ns(n), ps(n);
  stack<int> s;

  for (int i = n - 1; i >= 0; i--) {
    while (!s.empty() and v[i] <= v[s.top()]) {
      s.pop();
    }
    ns[i] = (s.empty() ? n : s.top());
    s.push(i);
  }

  while (!s.empty()) {
    s.pop();
  }

  for (int i = 0; i < n; i++) {
    while (!s.empty() and v[i] <= v[s.top()]) {
      s.pop();
    }
    ps[i] = (s.empty() ? -1 : s.top());
    s.push(i);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int width = ns[i] - ps[i] - 1;
    int area = width * v[i];
    ans = max(ans, area);
  }

  return ans;
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
    cout<< area(arr, n);
  }

  return 0;
}
