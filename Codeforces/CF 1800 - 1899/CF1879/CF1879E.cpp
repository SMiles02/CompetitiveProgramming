#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 105;
int c[N];
bitset<N> dp[N];
vector<int> e[N];

void dfs(int cur, int m) {
    int cd = 0;
    for (int i : e[cur]) {
        if (e[i].empty()) {
            continue;
        }
        ++cd;
        dfs(i, m);
    }
    for (int i = 1; i <= m; ++i) {
        dp[cur][i] = 1;
        for (int j : e[cur]) {
            if (dp[cur][i] && !e[j].empty()) {
                dp[cur][i] = 0;
                for (int k = 1; k <= m && dp[cur][i] == 0; ++k) {
                    if (dp[j][k] == 1 && (i < k || (i > k && e[j].size() > 1))) {
                        dp[cur][i] = 1;
                    }
                }
            }
        }
    }
}

void reconstruct(int cur, int i, int m) {
    // cerr << cur << " " << i << endl;
    for (int j : e[cur]) {
        c[j] = i;
        if (e[j].empty()) {
            continue;
        }
        for (int k = 1; k <= m; ++k) {
            if (dp[j][k] == 1 && (i < k || (i > k && e[j].size() > 1))) {
                reconstruct(j, k, m);
                break;
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n;
    vector<int> p(n + 1);
    bool found = false;
    for (int i = 2; i <= n; ++i) {
        cin >> p[i];
        e[p[i]].push_back(i);
    }
    dfs(1, 1);
    for (k = 1; k < n; ++k) {
        for (int x = 1; x <= n; ++x) {
            for (int y = 1; y <= n; ++y) {
                dp[x][y] = 0;
            }
        }
        dfs(1, k);
        for (int y = 1; y <= n; ++y) {
            if (dp[1][y]) {
                found = true;
                reconstruct(1, y, k);
                break;
            }
        }
        if (found) {
            break;
        }
    }
    cout << k << endl;
    for (int i = 2; i <= n; ++i) {
        cout << c[i];
        if (i != n) {
            cout << " ";
        }
    }
    cout << endl;
    while (true) {
        int t;
        cin >> t;
        if (t != 0) {
            return 0;
        }
        vector<int> f(k + 1);
        for (int i = 1; i <= k; ++i) {
            cin >> f[i];
        }
        for (int i = 1; i <= k; ++i) {
            if (f[i] == 1) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}