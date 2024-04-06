#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define PII pair<int, int>
const int N = 100010;
int main () {
    int n;
    cin >> n;
    vector<PII> intervals;
    while(n --) {
        int left, right;
        cin >> left >> right;
        intervals.emplace_back(left, right);
    }
    sort(intervals.begin(), intervals.end());
    int res = 0, ed = -2e9;
    for(auto interval : intervals) {
        if(interval.first > ed) {
            ed = interval.second;
            res ++;
        } else if(interval.second > ed) {
            ed = interval.second;
        }
    }
    cout << res;
    return 0;
}