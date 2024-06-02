/* 模拟散列表
维护一个集合，支持如下几种操作：

I x，插入一个整数 x；
Q x，询问整数 x 是否在集合中出现过；
现在要进行 N 次操作，对于每个询问操作输出对应的结果。

输入格式
第一行包含整数 N，表示操作数量。
接下来 N 行，每行包含一个操作指令，操作指令为 I x，Q x 中的一种。

输出格式
对于每个询问指令 Q x，输出一个询问结果，如果 x 在集合中出现过，则输出 Yes，否则输出 No。
每个结果占一行。

数据范围:
1≤N≤105
−10e9≤x≤10e9

输入样例：
5
I 1
I 2
I 3
Q 2
Q 5

输出样例：
Yes
No
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;
int h[N], e[N], ne[N], idx;

bool find(int value) {
    int k = (value % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i]) {
        if (e[i] == value) return true;
    }
    return false;
}

void insertTail(int value) {
    int k = (value % N + N) % N;
    e[idx] = value;
    ne[idx] = -1;
    int i = h[k];
    if (i == -1) {
        h[k] = idx ++;
    } else {
        for (; ne[i] != -1; i = ne[i]) {}
        ne[i] = idx ++;
    }
}

void insert(int value) {
    int k = (value % N + N) % N;
    e[idx] = value;
    ne[idx] = h[k];
    h[k] = idx ++;
}

int main() {
    memset(h, -1, sizeof(h));
    int n;
    cin >> n;
    while (n --) {
        char op;
        int value;
        cin >> op >> value;
        if (op == 'I') insert(value);
        if (op == 'Q') cout << (find(value) ? "Yes" : "No") << endl;
    }
    return 0;
}