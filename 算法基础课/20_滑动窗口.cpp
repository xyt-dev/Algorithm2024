#include<iostream>

using namespace std;
const int N = 1000010;

int que[N], hh = 0, tt = -1;
int arr[N];

int main() {
    int n, k;
    cin >> n >> k;
    for(int j = 0; j < n; ++ j) cin >> arr[j];
    for(int j = 0; j < n; ++ j) {
        if(j > k - 1 && arr[j - k] == que[hh]) ++ hh;
        while(tt >= hh && que[tt] > arr[j]) -- tt;
        que[++ tt] = arr[j];
        if(j >= k - 1) cout << que[hh] << " ";
    }
    cout << endl;
    tt = -1, hh = 0;
    for(int j = 0; j < n; ++ j) {
        if(j > k - 1 && arr[j - k] == que[hh]) ++ hh;
        while(tt >= hh && que[tt] < arr[j]) -- tt;
        que[++ tt] = arr[j];
        if(j >= k - 1) cout << que[hh] << " ";
    }
    return 0;
}