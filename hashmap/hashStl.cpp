#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  unordered_map<string, int> m;
  // m.insert({"apple", 10});
  m["mango"] = 20;
  m["kiwi"] = 20;
  m["orange"] = 20;
  m["tarbooz"] = 20;
  m["banana"] = 20;



  for (pair<string, int> p : m) {
    cout << p.first << " " << p.second << endl;
  }

  for (auto p : m) {
    cout << p.first << " " << p.second << endl;
  }

  // To Get Hash Table Size use bucket_count()
  for (int i = 0; i < m.bucket_count(); i++) {
    cout << i << "->";
    for (auto it = m.begin(i); it != m.end(i); it++) {
      cout << "(" << it->first << "," << it->second << ")";
    }
    cout << endl;
  }
  return 0;
}
