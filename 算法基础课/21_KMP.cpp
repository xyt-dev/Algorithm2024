#include<iostream>
#include<vector>

using namespace std;
const int N = 300010;

void calcNext(string str, int nextVal[]) {
    int i = 0, j = -1;
    nextVal[0] = -1;
    while (i < str.length()) { // next[]
        if (j == -1 || str[i] == str[j]) {
            ++ i, ++ j;
            nextVal[i] = j;
        } else {
            j = nextVal[j];
        }
    }
    for (int k = 1; k < str.length(); ++ k) { // nextVal[]
        nextVal[k] = (str[k] != str[nextVal[k]] ?
            nextVal[k] :
            nextVal[nextVal[k]]
        );
    }
}

vector<int> *kmp(string P, string S) {
    auto *matches = new vector<int>();
    int i = 0, j = 0, ne[N];
    calcNext(P, ne);
    while (i < S.length()) {
        if (j == -1 || S[i] == P[j]) {
            if (j == P.length() - 1) matches->push_back(i - j);
            ++ i, ++ j;
        } else {
            j = ne[j];
        }
    }
    return matches;
}


int main() {
    int n, m; // no need for string
    string P, S;
    cout << "Please input n, P, m, S: ";
    cin >> n >> P >> m >> S;
    vector<int> *matches = kmp(P, S);
    for(auto match : *matches) {
        cout << match << " ";
    }
    return 0;
}