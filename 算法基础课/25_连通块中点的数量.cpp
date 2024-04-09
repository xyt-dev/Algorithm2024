#include <iostream>

using namespace std;

const int N = 100010;
int p[N], cnt[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        p[i] = i;
        cnt[i] = 1;
    }
    while (m --) {
        string op;
        cin >> op;
        if (op == "C") {
            int a, b;
            cin >> a >> b;
            if (find(a) != find(b)) {  // NOTE
                cnt[find(b)] += cnt[find(a)];
                p[find(a)] = find(b);
            }
        } else if (op == "Q1") {
            int a, b;
            cin >> a >> b;
            cout << (find(a) == find(b) ? "Yes" : "No") << endl;
        } else if (op == "Q2") {
            int a;
            cin >> a;
            cout << cnt[find(a)] << endl;
        }
    }
    return 0;
}