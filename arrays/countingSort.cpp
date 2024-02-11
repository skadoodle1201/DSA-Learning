#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[1000];
    int countArray[10] = {0};

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 0) {
            countArray[0] += 1;
        }
        if (arr[i] == 1) {
            countArray[1] += 1;
        }
    }

    cout << countArray[0] << " " << countArray[1] << endl;

    for (int i = 0; i < countArray[0]; i++) {
        arr[i] = 0;
    }

    int placedI = 0;
    int j = countArray[0];
    while (placedI <= countArray[1]) {
        arr[j] = 1;
        j++;
        placedI++;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }

    return 0;
}