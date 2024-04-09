#include <iostream>

using namespace std;

const int N = 100010;
int p[N], d[N];
int lie;

int find(int x) {
    if (p[x] != x) {
        int t = find(p[x]); // NOTE
        d[x] += d[p[x]]; // NOTE
        p[x] = t;
    }
    return p[x];
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i) {
        p[i] = i;
    }
    while (k --) {
        int t, x, y;
        cin >> t >> x >> y;
        if (x > n || y > n || t == 2 && x == y) lie ++;
        else {
            int rel = 0;
            if (t == 2) rel = 1;
            if (find(x) == find(y)) {
                if (((d[x] - d[y]) % 3 + 3) % 3 != rel) lie ++;
            } else {
                int rx = find(x);
                p[rx] = find(y);
                d[rx] = d[y] - d[x] + rel;
                // NOTE d[原根节点]更新后必须先指向新的根节点后才能再次调用 find() 从而正确更新非根节点的权值
            }
        }
    }
    cout << lie << endl;
    return 0;
}