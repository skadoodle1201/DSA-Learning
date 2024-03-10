#include <functional>
#include <iostream>
#include <queue>
using namespace std;
class myCmp {
public:
  bool operator()(int a, int b) { return a < b; }
};
int main() {
  priority_queue<int> q;                             // By Default Max Heap
  priority_queue<int, vector<int>, greater<int>> q2; // MinHeap
  priority_queue<int, vector<int>, less<int>> q3;    // MaxHeap

  priority_queue<int, vector<int>, myCmp>
      q4; // Depends On Functor which heap will be created

  q.push(10);
  q.push(2);
  q.push(4);
  q.push(8);
  q.push(1);

  q2.push(10);
  q2.push(2);
  q2.push(4);
  q2.push(8);
  q2.push(1);

  q3.push(10);
  q3.push(2);
  q3.push(4);
  q3.push(8);
  q3.push(1);

  q4.push(10);
  q4.push(2);
  q4.push(4);
  q4.push(8);
  q4.push(1);

  cout << "Q Normal : " << endl;
  while (!q.empty()) {
    cout << q.top() << " ";
    q.pop();
  }

  cout << "Q Normal : " << endl;

  while (!q2.empty()) {
    cout << q2.top() << " ";
    q2.pop();
  }

  cout << "Q Normal : " << endl;

  while (!q3.empty()) {
    cout << q3.top() << " ";
    q3.pop();
  }

  cout << "Q Normal : " << endl;

  while (!q4.empty()) {
    cout << q4.top() << " ";
    q4.pop();
  }

  return 0;
}
