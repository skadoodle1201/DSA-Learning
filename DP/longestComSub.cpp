#include <cstring>
#include <iostream>
using namespace std;

void printLCS(const string &s1, const string &s2, int m, int n, int dp[][1000],
              string &x) {
  // base case
  if (m == 0 || n == 0) {
    reverse(x.begin(), x.end());
    cout << x << endl;
    return;
  }
  // recursive case
  if (s1[m - 1] == s2[n - 1]) {
    x.push_back(s1[m - 1]);
    printLCS(s1, s2, m - 1, n - 1, dp, x);
    x.pop_back();
  } else {
    if (dp[m][n - 1] == dp[m][n])
      printLCS(s1, s2, m, n - 1, dp, x);

    if (dp[m - 1][n] == dp[m][n])
      printLCS(s1, s2, m - 1, n, dp, x);
  }
}

int lcsUsingRec(string &s1, string &s2, int i, int j) {
  // base case
  if (i == 0 || j == 0)
    return 0;
  // recusive case
  if (s1[i - 1] == s2[j - 1])
    return 1 + lcsUsingRec(s1, s2, i - 1, j - 1);
  return max(lcsUsingRec(s1, s2, i, j - 1), lcsUsingRec(s1, s2, i - 1, j));
}

int topDown(string &s1, string &s2, int i, int j, int dp[][1000]) {
  // base case
  if (i == 0 || j == 0)
    return dp[i][j] = 0;
  // recusive case
  if (dp[i][j] != -1)
    return dp[i][j];
  if (s1[i - 1] == s2[j - 1])
    return dp[i][j] = 1 + topDown(s1, s2, i - 1, j - 1, dp);
  return dp[i][j] =
             max(topDown(s1, s2, i, j - 1, dp), topDown(s1, s2, i - 1, j, dp));
}

int bottomUp(const string &s1, const string &s2) {
  int dp[1000][1000] = {0};
  for (int i = 1; i <= s1.size(); i++) {
    for (int j = 1; j <= s2.size(); j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
    }
  }
  string x = "";
  printLCS(s1, s2, s1.size(), s2.size(), dp, x);
  return dp[s1.size()][s2.size()];
}
int main() {
  string s1 = "abcde";
  string s2 = "acbed";
  int dp[1000][1000];
  memset(dp, -1, sizeof dp);
  cout << lcsUsingRec(s1, s2, s1.size(), s2.size()) << endl;
  cout << topDown(s1, s2, s1.size(), s2.size(), dp) << endl;
  cout << bottomUp(s1, s2) << endl;

  return 0;
}
