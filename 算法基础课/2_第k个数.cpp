#include<iostream>
using namespace std;
const int N = 100000;
int Arr[N];
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
int quickSort(int arr[], int l, int r, int k) {
    if(r == l) return arr[r];
    int i = l - 1, j = r + 1, x = arr[(l + r) >> 1];
    while(i < j) {
        do ++i; while (arr[i] < x);
        do --j; while (arr[j] > x);
        if(i < j) swap(arr[i], arr[j]);
    }
    if(j < k) return quickSort(arr, j + 1, r, k);
    if(j >= k) return quickSort(arr, l, j, k);
}
int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++ i) {
        cin >> Arr[i];
    }
    cout << quickSort(Arr, 0, n - 1, k - 1);
    return 0;
}