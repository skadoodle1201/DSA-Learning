#include <iostream>
#include <stack>
using namespace std;

class Deque {
  int n;
  stack<int> s1, s2;

public:
  void addElements(int d) { s1.push(d); }

  void pop() {
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    cout << s2.top() << " ";
    s2.pop();
  }
};

int main() {
  int n;
  cin >> n;
  Deque que;
  for (int i = 0; i < n; i++) {
    que.addElements(i);
  }

  for (int i = 0; i < n; i++) {
    que.pop();
  }
  return 0;
}
