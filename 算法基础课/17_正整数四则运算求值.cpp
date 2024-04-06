#include<iostream>
#include<unordered_map>
#include<stack>

using namespace std;
const int N = 100010;
stack<char> ops;
stack<int> nums;
// 优先级表
unordered_map<char, int> h{{'+', 1},
                           {'-', 1},
                           {'*', 2},
                           {'/', 2},
                           {'(', 0}};

void eval() {
    int val1 = nums.top();
    nums.pop();
    int val2 = nums.top();
    nums.pop();
    char op = ops.top();
    ops.pop();
    int res;
    if (op == '+') res = val2 + val1;
    if (op == '-') res = val2 - val1;
    if (op == '/') res = val2 / val1;
    if (op == '*') res = val2 * val1;
    nums.push(res);
}

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (isdigit(s[i])) {
            int x = 0, j = i;
            while (j < s.size() && isdigit(s[j])) {
                x = x * 10 + s[j] - '0';
                ++ j;
            }
            nums.push(x);
            i = j - 1;
        } else if (s[i] == '(') {
            ops.push(s[i]);
        } else if (s[i] == ')') {
            while(ops.top() != '(')
                eval();
            ops.pop();
        } else {
            while(!ops.empty() && h[s[i]] <= h[ops.top()]) eval();
            ops.push(s[i]);
        }
    }
    while(!ops.empty()) eval();
    cout << nums.top() << endl;
    return 0;
}