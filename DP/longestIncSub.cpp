#include <climits>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > ans;

void printAllLIS(vector<int> dp, vector<int> a, vector<int> &v, int index,
                 int lisRemain, int lastEle) {
  // base case

  if (lisRemain == 0) {
    for (auto x : v) {
      cout << x << " ";
    }
    cout << endl;
    return;
  }
  if (index < 0)
    return;
  // recursion
  // ek bar curr ele ko include karlo agr voh lastEle se chota h and lis uss tak
  // lisRemaining ke equal h
  if ((lastEle >= a[index]) and (lisRemain == dp[index])) {
    v.push_back(a[index]);
    printAllLIS(dp, a, v, index - 1, lisRemain - 1, a[index]);
    v.pop_back();
  }

  // exclude curr element
  printAllLIS(dp, a, v, index - 1, lisRemain, lastEle);
}
int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  vector<int> dp(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < n; i++) {
    dp[i] = 1;
  }

  for (int i = 1; i < n; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (arr[i] >= arr[j]) {
        dp[i] = max(dp[j] + 1, dp[i]);
      }
    }
  }
  int mxLis = 0;
  int index;
  for (int k = 0; k < n; k++) {
    if (mxLis <= dp[k]) {
      mxLis = dp[k];
      index = k;
    }
  }
  vector<int> v;
  cout << mxLis << endl;

  printAllLIS(dp, arr, v, index, mxLis, INT_MAX);
  return 0;
}
