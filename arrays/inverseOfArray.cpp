#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[1000];
    int arr2[1000];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int j = 0; j < n; j++) {
        arr2[arr[j]] = j;
    }

    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }

    return 0;
}