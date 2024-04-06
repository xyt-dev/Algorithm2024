#include <iostream>
#define N 100000
using namespace std;
void quickSort(int [], int, int);
int main() {
    int n;
    cin >> n;
    int arr[N];
    for(int i = 1; i <= n; ++ i)
        cin >> arr[i];
    quickSort(arr, 1, n);
    for(int i = 1; i <= n; ++ i)
        cout << arr[i] << " ";
    return 0;
}
void swap(int &l, int &r) {
    int temp = l;
    l = r;
    r = temp;
}
void quickSort(int arr[], int l, int r) {
    if (l == r) return; // 可以写 ==
    int x = arr[(l + r) >> 1];
    int i = l - 1, j = r + 1;
    while (i < j) {
        do ++ i; while (arr[i] < x);
        do -- j; while (arr[j] > x);
        if (i < j) swap(arr[i], arr[j]);
    }
    quickSort(arr, l, j); quickSort(arr, j + 1, r);
}
