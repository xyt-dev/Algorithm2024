#include<iostream>
using namespace std;
const int N = 100010;
int stk[N], tt = -1;

int main() {
    int n;
    cin >> n;
    while(n --) {
        int x;
        cin >> x;
        while(tt >= 0 && stk[tt] >= x) -- tt;
        if(tt < 0) cout << -1 << " ";
        else cout << stk[tt] << " ";
        stk[++ tt] = x;
    }
    return 0;
}