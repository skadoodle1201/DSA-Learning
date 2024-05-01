#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int area(vector<int> h, int n) {
  vector<int> ns(n), ps(n);
  stack<int> s;
  int ans = 0;

  for (int i = n - 1; i >= 0; i--) {
    while (!s.empty() and h[i] <= h[s.top()]) {
      s.pop();
    }
    ns[i] = (s.empty() ? n : s.top());
    s.push(i);
  }

  while (!s.empty()) {
    s.pop();
  }

  for (int i = 0; i < n; i++) {
    while (!s.empty() and h[i] <= h[s.top()]) {
      s.pop();
    }
    ps[i] = (s.empty() ? 0 : s.top());
    s.push(i);
  }

  for (int i = 0; i < n; i++) {
    int withd = ns[i] - ps[i] - 1;
    int area = withd * h[i];
    ans = max(area, ans);
  }

  return ans;
}
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  int data;

  for (int i = 0; i < n; i++) {
    cin >> data;
    v[i] = data;
  }
  cout << area(v, n);
  return 0;
}
