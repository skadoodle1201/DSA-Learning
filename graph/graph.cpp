#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class Graph {
public:
  int n;
  list<int> *adj;

  Graph(int N) {
    n = N;
    adj = new list<int>[n];
  }

  void addEdge(int u, int v, bool biDirect = true) {
    adj[u].push_back(v);
    if (biDirect)
      adj[v].push_back(u);
  }

  void printEdges() {
    for (int i = 0; i < n; i++) {
      cout << i << "-->";
      for (auto d : adj[i]) {
        cout << d << ", ";
      }
      cout << endl;
    }
  }
};

template <typename T>
class genGraph {
    public :
     unordered_map<T, list<T>> adj;

     void addEdge(T u, T v, bool biDirect = true) {
       adj[u].push_back(v);
       if (biDirect)
         adj[v].push_back(u);
     }

     void printEdges() {
         for (auto v : adj) {
         cout << v.first << "-->";
         for (auto d : v.second) {
           cout << d << ", ";
         }
         cout << endl;
       }
     }
};

int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(0, 3);
  g.addEdge(2, 1);
  g.addEdge(2, 3);
  g.printEdges();

  genGraph<string> gStr;
  gStr.addEdge("Putin","Modi");
  gStr.addEdge("Yogi","Modi");
  gStr.addEdge("Prabhu","Modi");
  gStr.printEdges();

  return 0;
}
