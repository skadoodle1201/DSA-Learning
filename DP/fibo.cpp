#include <iostream>
#define mk(arr, n, v)                                                          \
  int *arr = new int[n + 1];                                                   \
  for (int i = 0; i <= n; i++) {                                               \
    arr[i] = v;                                                                \
  }
using namespace std;

int topDown(int n, int *arr) {
  if (n <= 1) {
    return arr[n] = n;
  }
  if (arr[n] != -1)
    return arr[n];
  return arr[n] = topDown(n - 1, arr) + topDown(n - 2, arr);
}

int bottomUp(int n){
    mk(dp,n,-1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}
int main() {
  int n;
  cin >> n;
  mk(arr, n, -1);
  cout << topDown(n, arr) << endl;
  cout << bottomUp(n)<<endl;

  return 0;
}
