#include<iostream>

using namespace std;
const int N = 1010;
int M[N][N];

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            cin >> M[i][j];
        }
    }
    for (int i = n; i >= 1; -- i) {
        for(int j = m; j >= 1; -- j) {
            M[i][j] = M[i][j] - M[i - 1][j] - M[i][j - 1] + M[i - 1][j - 1];
        }
    }
    while (q --) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        M[x1][y1] += c; M[x2 + 1][y2 + 1] += c;
        M[x1][y2 + 1] -= c; M[x2 + 1][y1] -= c;
    }
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            M[i][j] = M[i][j] + M[i - 1][j] + M[i][j - 1] - M[i - 1][j - 1];
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}