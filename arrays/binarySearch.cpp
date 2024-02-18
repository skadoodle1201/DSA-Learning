#include <iostream>

using namespace std;

int binarySearch(int *arr, int n, int target) {
    int start = 0;
    int end = n - 1;

    while (start < end) {
        int mid = (start + end) / 2;
        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    int arr[1000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    cout << binarySearch(arr, n, target);
    return 0;
}