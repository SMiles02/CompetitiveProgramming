#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<long long>>& v, int n, int x, int y, int z) {
    int p = 1;
    for (int i = 1; i <= n; ++i) {
        if (v[x][i] * 3 < v[0][n]) {
            continue;
        }
        while (p <= n && (v[y][p] - v[y][i]) * 3 < v[0][n]) {
            ++p;
        }
        if (p <= n && (v[z][n] - v[z][p]) * 3 >= v[0][n]) {
            vector<array<int, 2>> ans(3);
            ans[x] = {1, i};
            ans[y] = {i + 1, p};
            ans[x ^ y ^ 3] = {p + 1, n};
            for (auto j : ans) {
                cout << j[0] << " " << j[1] << " ";
            }
            cout << "\n";
            return true;
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<long long>> v(3, vector<long long>(n + 1));
    for (int i = 0; i < 3; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> v[i][j];
            v[i][j] += v[i][j - 1];
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (i != j && i != k && j != k && check(v, n, i, j, k)) {
                    return;
                }
            }
        }
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}