#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

void solve() {
    int n, q;
    cin >> n >> q;
    int a[n * 2 + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    array<ll, 3> l[n + 1], r[n + 1]; // range_left, range_right, id
    l[1] = {1, 1, 1};
    r[1] = {n, n, n};
    l[2] = {1, 2, n + 1};
    r[2] = {n - 1, n, n * 2 - 1};
    for (int i = 3; i <= n; ++i) {
        l[i] = {r[i - 2][0], l[i - 1][1], r[i - 1][2] + 1};
        r[i] = {n - i + 1, n, r[i - 1][2] + n - 1};
    }
    vector<vector<int>> next(n * 2 + 1, vector<int>(30, n * 2 + 1));
    for (int i = n * 2 - 1; i >= 1; --i) {
        for (int j = 0; j < 30; ++j) {
            if (a[i + 1] & (1 << j)) {
                next[i][j] = i + 1;
            }
            else {
                next[i][j] = next[i + 1][j];
            }
        }
    }
    vector<array<ll, 2>> v;
    for (int i = 1; i <= n; ++i) {
        int cur_or = a[i];
        v.push_back({a[i], i});
        while (true) {
            int nearest = n * 2 + 1;
            for (int j = 0; j < 30; ++j) {
                if ((cur_or & (1 << j)) == 0) {
                    nearest = min(nearest, next[i][j]);
                }
            }
            if (nearest == n * 2 + 1) {
                break;
            }
            cur_or |= a[nearest];
            if (nearest != n + 1) {
                if (l[nearest - i + 1][0] <= i) {
                    v.push_back({cur_or, l[nearest - i + 1][2] + i - l[nearest - i + 1][0]});
                }
                else {
                    v.push_back({cur_or, l[nearest - i + 1][2] + i + n - l[nearest - i + 1][0]});
                }
            }
        }
    }
    sort(v.begin(), v.end());
    for (int i = v.size() - 2; i >= 0; --i) {
        v[i][1] = min(v[i][1], v[i + 1][1]);
    }
    while (q--) {
        int x;
        cin >> x;
        int l = 0, r = v.size() - 1, m;
        if (x >= v.back()[0]) {
            cout << "-1\n";
            continue;
        }
        while (l < r) {
            m = l + (r - l) / 2;
            if (v[m][0] <= x)
                l = m + 1;
            else
                r = m;
        }
        cout << v[l][1] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}