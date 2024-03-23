#include <iostream>
#include <string>
using namespace std;

int main() {
  pair<int, int> p;
  p.first = 10;
  p.second = 20;

  pair<string, int> p1 = {"mango", 20};
  pair<string, int> p2({"apple", 30});
  pair<string, int> p3(make_pair("banana", 40));
  pair<string, int> p4 = make_pair("pineapple", 50);
  pair<int, int> p5(p); // WIll Make A Deep Copy
  cout << p.first << " " << p.second << endl;
  cout << p1.first << " " << p1.second << endl;
  cout << p2.first << " " << p2.second << endl;
  cout << p3.first << " " << p3.second << endl;
  cout << p4.first << " " << p4.second << endl;
  cout << p5.first << " " << p5.second << endl;

  return 0;
}
