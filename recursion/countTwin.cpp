#include <iostream>

using namespace std;

void countTwin(char *s, int n, int i, int &count) {
    // base case
    if (i == n - 1) {
        return;
    }

    // recursive case
    if (s[i + 2] != '\0' and s[i] == s[i + 2]) {
        count += 1;
    }
    countTwin(s, n, i + 1, count);
}
int main() {
    char s[10000];
    cin.getline(s, 1000);
    int count = 0;
    countTwin(s, strlen(s), 0, count);
    cout << count;
    return 0;
}