#include <iostream>
#include <map>

using namespace std;

int countMajority(int* arr, int n) {
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        if (m[arr[i]]) {
            m[arr[i]] += 1;
        } else {
            m[arr[i]] = 1;
        }
    }

    map<int, int>::iterator it = m.begin();
    map<int, int>::iterator majorityElement = it;
    while (it != m.end()) {
        if (it->second > majorityElement->second) {
            majorityElement = it;
        }
        it++;
    }

    return majorityElement->first;
}

int main() {
    int n;
    cin >> n;
    int arr[1000];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int majority = countMajority(arr, n);
    cout << majority << endl;
    return 0;
}