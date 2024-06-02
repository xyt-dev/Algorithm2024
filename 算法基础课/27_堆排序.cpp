/* 堆排序 
输入一个长度为 n 的整数数列，从小到大输出前 m 小的数。

输入格式
第一行包含整数 n和 m。

第二行包含 n 个整数，表示整数数列。

输出格式共一行，包含 m 个整数，表示整数数列中前 m 小的数。

数据范围 1≤m≤n≤105， 1≤数列中元素≤109

输入样例：
5 3
4 5 1 3 2

输出样例：
1 2 3
*/

#include <iostream>

using namespace std;

const int N = 100010;
int h[N], n;

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void down(int u) {
    int t = u;
    if (2 * u <= n && h[t] > h[2 * u]) t = 2 * u;
    if (2 * u + 1 <= n && h[t] > h[2 * u + 1]) t = 2 * u + 1; 
    if (t != u) {
        swap(h[t], h[u]);
        down(t);
    }
}

int main() {
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> h[i];
    }
    for (int i = n / 2; i >= 1; i --) {
        down(i);
    }
    for (int i = 1; i <= m; i ++) {
        cout << h[1] << " ";
        swap(h[1], h[n --]);
        down(1);
    }
    return 0;
}