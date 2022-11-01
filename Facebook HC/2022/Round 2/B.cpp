#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 1e9 + 7, N = 1e6;
int a[N][4];

void solve() {
    int n, k, a, cur = 0;
    set<ll> ans;
    cin >> n >> k;
    set<int> days;
    map<int, int> m;
    vector<array<int, 2>> prev(n * 2);
    vector<array<ll, 3>> edge(n * 2);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j)
            cin >> a[i][j];
        days.insert(a[i][0]);
        days.insert(a[i][1]);
    }
    for (int i : days)
        m[i] = cur++;
    for (int i = 0; i < n; ++i) {
        a[i][0] = m[a[i][0]];
        a[i][1] = m[a[i][1]];
        prev[a[i][0]].push_back({a[i][2], id});
        edge[a[i][1]].push_back({a[i][0]});
    }
    for (int i = 0; i < n * 2; ++i) {
        sort(prev[i].begin(), prev[i].end());
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}