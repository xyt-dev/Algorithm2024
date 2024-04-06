#include<iostream>
using namespace std;
const int N = 100010;
int A[N];
int bsearchL(int q[], int l, int r, int val) {
    while(l < r) {
        int mid = (l + r) >> 1;
        if (q[mid] >= val) r = mid;
        if (q[mid] < val) l = mid + 1;
    }
    return q[l] == val ? l : -1;
}
int bsearchR(int q[], int l, int r, int val) {
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(q[mid] > val) r = mid - 1;
        if(q[mid] <= val) l = mid;
    }
    return q[l] == val ? l : -1;
}
int main() {
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; ++ i) {
        cin >> A[i];
    }
    while(q --) {
        int val;
        cin >> val;
        cout << bsearchL(A, 0, n - 1, val) << " " << bsearchR(A, 0, n - 1, val) << "\n";
    }
    return 0;
}