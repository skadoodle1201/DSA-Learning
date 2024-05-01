#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> stock(n);

  for (int i = 0; i < n; i++) {
    cin >> stock[i];
  }

  vector<int> S(n);
  stack<int> s;
  S[0]=1;
  s.push(0);
  for (int i = 1; i < n; i++) {
    while (!s.empty() and stock[i] >= stock[s.top()]) {
      s.pop();
    }
    S[i] = (s.empty() ? (i + 1) : (i - s.top()));
    s.push(i);
  }

  for(auto d : S){
      cout << d << " ";
  }
  return 0;
}
