#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
bool compare(vector<int> a, vector<int> b) {
  if (a[0] == b[0]) {
    return a[1] < b[1];
  }
  return a[0] < b[0];
}

class Solution {
public:
  int minMeetingRoom(vector<vector<int> > &v) {
    sort(v.begin(), v.end(), compare);
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < v.size(); i++) {
      if (q.empty()) {
        q.push(v[i][1]);
      } else {
        if (v[i][0] >= q.top()) {
          q.pop();
        }
        q.push(v[i][1]);
      }
    }

    return q.size();
  }
};
