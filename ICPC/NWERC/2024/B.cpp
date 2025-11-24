#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7, K = 6;
int a[N];
set<int> s[N][K], gs[K];
vector<int> e[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i][1].insert(a[i]);
        gs[1].insert(a[i]);
    }
    for (int j = 2; j < K; ++j) {
        for (int i = 1; i <= n; ++i) {
            for (int k : e[i]) {
                for (int x : s[k][j - 1]) {
                    s[i][j].insert(k * 2 + a[i]);
                }
            }
            for (int x : s[i][j]) {
                gs[j].insert(x);
            }
        }
    }
    if (gs[1].size() != 2) {
        cout << "1\n";
    }
    else if (gs[2].size() != 4) {
        cout << "2\n";
    }
    else if (gs[3].size() != 8) {
        cout << "3\n";
    }
    else if (gs[4].size() != 16) {
        cout << "4\n";
    }
    else if (gs[5].size() != 32) {
        cout << "5\n";
    }
    else {
        cout << "infinity\n";
    }
    return 0;
}