#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[1000];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int countZero = 0;
    for (int i = 0; i < n; i++) {
        countZero += 1;
        if (arr[i] == 0) {
        }
    }
}