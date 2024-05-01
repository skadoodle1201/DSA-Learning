#include <iostream>
using namespace std;

int nStair(int n, int k, int *dp) {
  if (n == 0) {
    return dp[n] = 1;
  }
  if (n < 0)
    return 0;
  if (dp[n] != -1)
    return dp[n];

  int ans = 0;
  for (int i = 1; i < k; i++) {
    ans += nStair(n, k, dp);
  }
  return dp[n] = ans;
}

int bottomUp(int n, int k) {
  int dp[1000] = {0};
  dp[0] = 1;
  dp[1] = 1;
  for(int i = 2; i < n; i++){
      for(int j = 1; j <= k; j++){
          dp[i] += (i-j >= 0 ) ? dp[i - j] : 0;
      }
  }
  return dp[n];
}

int main() {
  int n, k;
  cin >> n >> k;
  int dp[1000] = {-1};
  cout << nStair(n, k, dp) << endl;
  return 0;
}
