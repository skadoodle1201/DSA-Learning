#include <cstring>
#include <iostream>
using namespace std;

int knapsackRec(int n, int *wt, int *price, int cap) {
  if (n == 0 || cap == 0) {
    return 0;
  }

  int op1, op2;
  op1 = op2 = INT_MIN;

  if (cap >= wt[n - 1]) {
    op1 = price[n - 1] + knapsackRec(n - 1, wt, price, cap - wt[n - 1]);
  }
  op2 = knapsackRec(n - 1, wt, price, cap);

  return max(op1, op2);
}

int topDown(int n, int *wt, int *price, int cap, int dp[][100]) {
  if (n == 0 || cap == 0) {
    return dp[n][cap] = 0;
  }

  int op1, op2;
  op1 = op2 = INT_MIN;
  if (dp[n][cap] != -1)
    return dp[n][cap];
  if (cap >= wt[n - 1]) {
    op1 = price[n - 1] + topDown(n - 1, wt, price, cap - wt[n - 1], dp);
  }
  op2 = topDown(n - 1, wt, price, cap, dp);

  return dp[n][cap] = max(op1, op2);
}

int bottomUp(int items, int *wt, int *price, int cap) {
  int dp[100][100] = {0};
  for (int n = 1; n <= items; n++) {
    for (int c = 1; c <= cap; c++) {
      int op1, op2;
      op1 = op2 = INT_MIN;
      if (c >= wt[n - 1]) {
        op1 = price[n - 1] + dp[n - 1][c - wt[n - 1]];
      }
      op2 = dp[n - 1][c];
      dp[n][c] = max(op1, op2);
    }
  }

  return dp[items][cap];
}

int main() {
  int price[] = {4, 5, 6, 3};
  int wt[] = {2, 3, 3, 2};
  int dp[100][100];
  memset(dp, -1, sizeof dp);

  int n = sizeof(price) / sizeof(int);
  int cap = 4;
  cout << knapsackRec(n, wt, price, cap) << endl;
  cout << topDown(n, wt, price, cap, dp) << endl;
  cout << bottomUp(n, wt, price, cap) << endl;

  return 0;
}
