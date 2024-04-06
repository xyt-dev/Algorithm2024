#include<iostream>
using namespace std;
const int N = 100010;
int top = -1, st[N];
int main() {
    int M;
    cin >> M;
    while (M --) {
        string op;
        cin >> op;
        if (op == "push") {
            int x;
            cin >> x;
            st[++ top] = x;
        } else if (op == "pop") {
            -- top;
        } else if (op == "empty") {
            cout << ((top == -1) ? "YES" : "NO") << "\n";
        } else if (op == "query") {
            cout << st[top] << "\n";
        }
    }
    return 0;
}