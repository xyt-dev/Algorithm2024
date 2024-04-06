#include<iostream>
using namespace std;
const int N = 100010;
#define LOW_BIT(X) ((X)&(-(X)))
int main () {
    int n;
    cin >> n;
    while(n --) {
        int x, res = 0;
        cin >> x;
        while(LOW_BIT(x) != 0) {
            res++;
            x -= LOW_BIT(x);
        }
        cout << res << " ";
    }
    return 0;
}