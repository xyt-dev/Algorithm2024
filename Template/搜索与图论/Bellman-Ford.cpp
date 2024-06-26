#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
const int M = 10010;
int n, m, k;
int dist[N];
int backup[N]; // 备份dist
struct Edge{
    int a, b, w;
}edges[M]; // 随便存,只需要能遍历所有边即可

int bellman_ford(){
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for(int i = 0; i < k; ++ i){ // k为最大松弛边数(最多只能经过k条边)
        memcpy(backup, dist, sizeof(dist)); // 备份dist,避免串联更新 松弛边数一次只增加1
        for(int j = 0; j < m; ++ j){
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            if(dist[b] > backup[a] + w){
                dist[b] = backup[a] + w;
            }
        }
    }
    if(dist[n] > 0x3f3f3f3f / 2) return 2e9; // 注: 1.可能有负权边更新了无穷大  2.dist可能为负
    return dist[n];
}
// [有边数限制的最短路]
int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < m; ++ i){
        int x, y, z;
        cin >> x >> y >> z;
        edges[i].a = x;
        edges[i].b = y;
        edges[i].w = z;
    }
    int ans = bellman_ford();
    if(ans == 2e9) cout << "impossible";
    else cout << ans;
    return 0;
}