#include <iostream>

using namespace std;

const int N = 100010;
int trie[N][26], idx, cnt[N];
char str[N];

void insert(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; ++ i) {
        int u = str[i] - 'a';
        if (trie[p][u] == 0) trie[p][u] = ++ idx;
        p = trie[p][u];
    }
    cnt[p] ++;
}

int query(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; ++ i) {
        int u = str[i] - 'a';
        if (trie[p][u] == 0) return 0;
        p = trie[p][u];
    }
    return cnt[p];
}

int main() {
    int n;
    cin >> n;
    while (n --) {
        char op[2];
        cin >> op >> str;
        if (*op == 'I') insert(str);
        else if (*op == 'Q') cout << query(str) << endl;
    }
    return 0;
}