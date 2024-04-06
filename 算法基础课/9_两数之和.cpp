#include "iostream"
using namespace std;
const int N = 100010;
int A[N], B[N];
int main() {
    int n, m, x;
    cin >> n >> m >> x;
    for(int i = 0; i < n; ++ i) {
        cin >> A[i];
    }
    for(int i = 0; i < m; ++ i) {
        cin >> B[i];
    }
    for(int i = 0, j = m - 1; i < n && j >= 0;) {
        if(A[i] + B[j] > x) -- j;
        else if(A[i] + B[j] < x) ++ i;
        else {
            cout << i << " " << j << endl;
            ++ i;
            -- j;
        }
    }
    return 0;
}