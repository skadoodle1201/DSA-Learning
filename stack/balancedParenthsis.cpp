#include <iostream>
#include <stack>

using namespace std;

bool isBalanced(char *a) {
    stack<char> s;

    for (int i = 0; a[i] != '\0'; i++) {
        char ch = a[i];
        switch (ch) {
            case '(':
            case '{':
            case '[':
                s.push(ch);
                break;
            case ')':
                if (!s.empty() and s.top() == '(') {
                    s.pop();
                } else {
                    return false;
                }
                break;
            case '}':
                if (!s.empty() and s.top() == '{') {
                    s.pop();
                } else {
                    return false;
                }
                break;
            case ']':
                if (!s.empty() and s.top() == '[') {
                    s.pop();
                } else {
                    return false;
                }
                break;
        }
    }
    if (!s.empty()) {
        return false;
    }
    return true;
}
int main() {
    char a[1000];
    cin.getline(a, 1000);
    cout << "Is Balanced Paranethsis : " << isBalanced(a);
    return 0;
}