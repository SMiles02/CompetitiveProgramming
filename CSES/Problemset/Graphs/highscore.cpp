#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = -1e18;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> e(m);
    vector<ll> d(n + 1, INF), f(n + 1, INF);
    for (auto &i : e)
        for (int j = 0; j < 3; ++j)
            cin >> i[j];
    d[1] = 0;
    f[n] = 0;
    for (int _ = 1; _ < n; ++_)
        for (auto i : e) {
            if (d[i[0]] != INF)
                d[i[1]] = max(d[i[1]], d[i[0]] + i[2]);
            if (f[i[1]] != INF)
                f[i[0]] = max(f[i[0]], f[i[1]] + i[2]);
        }
    for (auto i : e)
        if (d[i[0]] + i[2] > d[i[1]] && d[i[0]] != INF && f[i[0]] != INF) {
            cout << -1;
            return 0;
        }
    cout << d[n];
    return 0;
}