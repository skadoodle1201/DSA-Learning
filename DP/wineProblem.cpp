#include <cstring>
#include <iostream>
#include <iterator>
using namespace std;

// int maxProfit(int *wine,int )

int wineProblem(int *wine, int l, int r, int day) {
	// base case
	if (l > r) return 0;

	// recursive case
	int op1 = wine[l] * day + wineProblem(wine, l + 1, r, day + 1);
	int op2 = wine[r] * day + wineProblem(wine, l, r - 1, day + 1);
	return max(op1, op2);
}

int wineProblem1(int *wine, int l, int r, int n) {
	// base case
	if (l > r) return 0;

	// recursive case
	int day = n - (r - l);
	int op1 = wine[l] * day + wineProblem1(wine, l + 1, r, n);
	int op2 = wine[r] * day + wineProblem1(wine, l, r - 1, n);
	return max(op1, op2);
}
int topDown(int *wine, int day, int l, int r, int dp[][100]) {
  if (l > r) {
    return dp[l][r] = 0;
  }

  if (dp[l][r] != -1)
    return dp[l][r];

  int op1 = (day * wine[l]) + topDown(wine, day + 1, l + 1, r, dp);
  int op2 = (day * wine[r]) + topDown(wine, day + 1, l, r - 1, dp);

  return dp[l][r] = max(op1, op2);
}

int bottomUp(int *wine, int n) {
    int dp[100][100] = {0};
    for(int i = n-1;i>=0;i--){
        for(int j = i; j<n ;j ++){
            int currDay = n -(j -i);
            int op1 =
        }
    }
}
int main() {
  int wine[] = {2, 3, 5, 1, 4};
  int n = sizeof(wine) / sizeof(int);

  int dp[100][100];
  memset(dp, -1, sizeof dp);
  cout << topDown(wine, 1, 0, n - 1, dp) << endl;
  return 0;
}
