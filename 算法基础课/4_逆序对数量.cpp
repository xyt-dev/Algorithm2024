#include<iostream>
using namespace std;
const int N = 100010;
int A[N];
int tmp[N];
long long inverseCount = 0;
void mergeSort(int arr[], int l, int r) {
    if(l == r) return;
    int mid = (l + r) >> 1;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r) {
        if(arr[i] <= arr[j]) tmp[k ++] = arr[i ++];
        else {
            tmp[k ++] = arr[j ++];
            inverseCount += mid - i + 1;
        }
    }
    while(i <= mid) tmp[k ++] = arr[i ++];
    while(j <= r) tmp[k ++] = arr[j ++];
    for(int m = l, n = 0; m <= r; m ++, n ++) {
        arr[m] = tmp[n];
    }
}
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++ i) {
        cin >> A[i];
    }
    mergeSort(A, 0, n - 1);
    cout << inverseCount;
    return 0;
}
