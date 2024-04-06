#include<iostream>
using namespace std;
const int N = 100010;
int q[N], s[N];
int main() {
    int n;
    cin >> n;
    int max = 0;
    for(int i = 0, j = 0; i < n; ++ i) {
        cin >> q[i];
        s[q[i]] ++;
        while(s[q[i]] > 1) -- s[q[j ++]];
        if(i - j + 1 > max) max = i - j + 1;
    }
    cout << max;
    return 0;
}