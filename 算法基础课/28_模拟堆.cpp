/* 模拟堆
维护一个集合，初始时集合为空，支持如下几种操作：

I x，插入一个数 x；
PM，输出当前集合中的最小值；
DM，删除当前集合中的最小值（数据保证此时的最小值唯一）；
D k，删除第 k 个插入的数；
C k x，修改第 k 个插入的数，将其变为 x；
现在要进行 N 次操作，对于所有第 2 个操作，输出当前集合的最小值。

输入格式
第一行包含整数 N
接下来 N 行，每行包含一个操作指令，操作指令为 I x，PM，DM，D k 或 C k x 中的一种。

输出格式
对于每个输出指令 PM，输出一个结果，表示当前集合中的最小值。
每个结果占一行。

数据范围
1≤N≤105
−109≤x≤109
数据保证合法 

输入样例：
8
I -10
PM
I -10
D 1
C 2 8
I 6
PM
DM

输出样例：
-10
6
*/

#include <iostream>

using namespace std;

const int N = 100010;
int h[N], hp[N], ph[N], sz, idx;

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void swap_heap(int a, int b) { // NOTE
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u) {
    int t = u;
    while (2 * u <= sz || 2 * u + 1 <= sz) {
        if (2 * u <= sz && h[t] > h[2 * u]) t = 2 * u;
        if (2 * u + 1 <= sz && h[t] > h[2 * u + 1]) t = 2 * u + 1;
        if (t == u) return;
        swap_heap(t, u);
        u = t;
    }
}


void up(int u) {
    int t = u;
    while (u / 2 > 0) {
        if (h[t] < h[u / 2]) t = u / 2;
        if (t == u) return;
        swap_heap(t, u);
        u = t;
    }
}

int main() {
    int n;
    cin >> n;
    while (n --) {
        string op;
        cin >> op;
        if (op == "I") {
            int x;
            cin >> x;
            sz ++, idx ++;
            hp[sz] = idx, ph[idx] = sz;
            h[sz] = x;
            up(sz);
        } else if (op == "PM") {
            cout << h[1] << endl;
        } else if (op == "DM") {
            swap_heap(1, sz);
            sz --;
            down(1);
        } else if (op == "D") {
            int k;
            cin >> k;
            int u = ph[k];
            swap_heap(u, sz);
            sz --;
            up(u); // NOTE
            down(u); // NOTE
        } else if (op == "C") {
            int k, x;
            cin >> k >> x;
            int u = ph[k];
            h[u] = x;
            up(u); // NOTE
            down(u); // NOTE
        }
    }
    return 0;
}