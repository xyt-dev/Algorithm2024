#include<iostream>
using namespace std;
const int N = 100010;
int A[N], B[N];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++ i)
        cin >> A[i];
    for(int i = 0; i < m; ++ i)
        cin >> B[i];
    int i = 0;
    for(int j = 0; j < m && i < n; ++ j) // i < n 防止越界
        if(A[i] == B[j]) ++ i;
    cout << ((i == n) ? "Yes" : "No");
    return 0;
}