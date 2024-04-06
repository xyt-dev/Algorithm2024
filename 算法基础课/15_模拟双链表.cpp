#include<iostream>
using namespace std;
const int N = 100010;
int idx, l[N], r[N], e[N];
void init() {
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}
void insertL(int k, int val) {
    e[idx] = val;
    l[idx] = l[k];
    r[idx] = k;
    r[l[k]] = idx;
    l[k] = idx ++;
}
void insertR(int k, int val) {
    e[idx] = val;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx ++;
}
void remove(int k) {
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}
void list() {
    for(int k = r[0]; k != 1; k = r[k]) {
        cout << e[k] << " ";
    }
}
int main() {
    int M;
    cin >> M;
    init();
    while(M --) {
        string op;
        cin >> op;
        if(op == "IL") {
            int k, x;
            cin >> k >> x;
            insertL(k + 1, x);
        } else if (op == "IR") {
            int k, x;
            cin >> k >> x;
            insertR(k + 1, x);
        } else if (op == "L") {
            int x;
            cin >> x;
            insertR(0, x);
        } else if (op == "R") {
            int x;
            cin >> x;
            insertL(1, x);
        } else if (op == "D") {
            int k;
            cin >> k;
            remove(k + 1);
        }
    }
    list();
    return 0;
}