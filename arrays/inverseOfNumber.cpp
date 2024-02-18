#include <iostream>
#include <string>
using namespace std;

int main() {
    string arr = "32145";
    int numbInverse[100];
    // getline(cin, arr);
    int i = 1;
    for (int j = arr.size() - 1; j >= 0; j--) {
        int value = arr[j] - '0';
        numbInverse[arr.size() - value] = i;
        i++;
    }

    for (int k = 0; arr[k] != '\0'; k++) {
        cout << numbInverse[k];
    }

    return 0;
}