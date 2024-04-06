#include "iostream"
using namespace std;
const int N = 10010;
int presum[N][N];
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; ++ i) {
        for(int j = 1; j <= m; ++ j) {
            int val;
            cin >> val;
            presum[i][j] = val + presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1];
        }
    }
    while(q --) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << presum[x2][y2] - presum[x2][y1 - 1] - presum[x1 - 1][y2] + presum[x1 - 1][y1 - 1] << '\n';
    }
    return 0;
}