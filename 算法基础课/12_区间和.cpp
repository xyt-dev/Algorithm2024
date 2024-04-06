#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 300010; // 注意最多会有 300000 个离散点
#define PII pair<int, int>
vector<int> alls;
vector<PII> queries, adds;
int val[N];
int sum[N];
int indexOf(int v) {
    int l = 0, r = (int)alls.size() - 1;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(alls[mid] >= v) r = mid;
        else l = mid + 1;
    }
    return alls[l] == v ? (l + 1) : 0; // 下标从 1 开始
}
int main () {
    int n, m;
    cin >> n >> m;
    while(n --) {
        int x, c;
        cin >> x >> c;
        adds.emplace_back(x, c);
        alls.push_back(x);
    }
    while(m --) {
        int l, r;
        cin >> l >> r;
        queries.emplace_back(l, r);
        alls.push_back(l);
        alls.push_back(r);
    }
    // 去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    for(auto & add : adds)
        val[indexOf(add.first)] += add.second;
    for(int i = 1; i <= alls.size(); ++ i) {
        sum[i] = sum[i - 1] + val[i];
    }
    for(auto &query : queries) {
        cout << sum[indexOf(query.second)] - sum[indexOf(query.first) - 1] << "\n";
    }
    return 0;
}