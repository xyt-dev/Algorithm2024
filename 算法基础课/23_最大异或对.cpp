#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100010, M = 31 * N;
int trie[M][2], idx;

void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i --) {
        int u = x >> i & 1;
        if (trie[p][u] == 0) trie[p][u] = ++ idx;
        p = trie[p][u];
    }
}

int search(int x) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i --) {
        int u = x >> i & 1;
        if (trie[p][!u]) {
            p = trie[p][!u];
            res = res * 2 + 1;
        } else {
            p = trie[p][u];
            res = res * 2 + 0;
        }
    }
    return res;
}

int main() {
    int n, res = 0;
    cin >> n; 
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        insert(x);
        res = max(res, search(x));
    }
    cout << res << endl;
    return 0;
}