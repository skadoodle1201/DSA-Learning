#include <functional>
#include <iostream>
#include <queue>

using namespace std;

void print(priority_queue<int, vector<int>, greater<int> > q) {
  while (!q.empty()) {
    cout << q.top() << " ";
    q.pop();
  }
}
int main() {
  int cnt = 0, num, k;
  priority_queue<int, vector<int>, greater<int> > q;
  cin >> k;
  while (true) {
    cin >> num;
    if (num == -1) {
      print(q);
      continue;
    }

    if (cnt < k) {
      q.push(num);
      cnt++;
    } else {
      if (q.top() < num) {
        q.pop();
        q.push(num);
      }
    }
  }
  return 0;
}
