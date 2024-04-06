#include<iostream>

using namespace std;
const int N = 100010;

int que[N], hh = 0, tt = -1;

int main() {
    int M;
    string op;
    cin >> M;
    while(M --) {
        cin >> op;
        if (op == "push") {
            int x;
            cin >> x;
            que[++ tt] = x;
        } else if (op == "pop") {
            ++ hh;
        } else if (op == "empty") {
            cout << (tt < hh ? "YES" : "NO") << endl;
        } else if (op == "query") {
            cout << que[hh] << endl;
        }
    }
    return 0;
}