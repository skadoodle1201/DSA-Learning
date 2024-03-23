#include <climits>
#include <iostream>
#include <vector>
#define mk(arr, n, v)                                                          \
  int *arr = new int[n];                                                       \
  for (int i = 0; i <= n; i++) {                                               \
    arr[i] = v;                                                                \
  }
using namespace std;

int minCoin(int amount, vector<int> deno, int n) {
  // base case
  if (amount == 0) {
    return 0;
  }
  // recursion
  int ans = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (deno[i] <= amount) {
      int changeSteps = minCoin(amount - deno[i], deno, n);
      if (changeSteps != INT_MAX)
        ans = min(ans, changeSteps + 1);
    }
  }
  return ans;
}

int topDown(int amount, vector<int> deno, int n, int *dp) {
  // base case
  if (amount == 0) {
    return dp[amount] = 0;
  }

  if (dp[amount] != -1)
    return dp[amount];
  // recursion
  int ans = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (deno[i] <= amount) {
      int changeSteps = topDown(amount - deno[i], deno, n, dp);
      if (changeSteps != INT_MAX)
        ans = min(ans, changeSteps + 1);
    }
  }
  dp[amount] = ans;
  return ans;
}

int bottomUp(int amount, vector<int> deno, int n) {
  mk(dp, amount, INT_MAX);
  dp[0] = 0;
  for (int a = 1; a <= amount; a++) {
    for (int i = 0; i < n; i++) {
      if (deno[i] <= a) {
        int smallerValue = a - deno[i];
        if (smallerValue != INT_MAX) {
          dp[a] = min(dp[a], dp[smallerValue] + 1);
        }
      }
    }
  }
  return dp[amount];
}
int main() {
  int n;
  cin >> n;
  vector<int> deno(n);

  for (int i = 0; i < n; i++) {
    cin >> deno[i];
  }
  int amount;
  cin >> amount;
  mk(dp, amount, -1);
  cout << topDown(amount, deno, 3, dp) << endl;
  cout << bottomUp(amount, deno, 3) << endl;
  cout << minCoin(amount, deno, 3) << endl;


  return 0;
}
