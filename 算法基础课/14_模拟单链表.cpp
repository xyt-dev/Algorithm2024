#include<iostream>
using namespace std;
const int N = 100010;
int head, idx, ne[N], e[N];
void init() {
    head = -1;
    idx = 0;
}
void insert(int k, int val) {
    e[idx] = val;
    ne[idx] = ne[k - 1];
    ne[k - 1] = idx ++;
}
void insertHead(int val) {
    e[idx] = val;
    ne[idx] = head;
    head = idx ++;
}
void remove(int k) {
    ne[k - 1] = ne[ne[k - 1]];
}
void list() {
    int k = head;
    while(k != -1) {
        cout << e[k] << " ";
        k = ne[k];
    }
}
int main() {
    int M;
    cin >> M;
    init();
    while(M --) {
        char operation;
        cin >> operation;
        if(operation == 'H') {
            int x;
            cin >> x;
            insertHead(x);
        } else if (operation == 'D') {
            int k;
            cin >> k;
            if(k == 0) head = ne[head];
            else remove(k);
        } else if (operation == 'I') {
            int k, x;
            cin >> k >> x;
            insert(k, x);
        }
    }
    list();
    return 0;
}