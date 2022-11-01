#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool solve_case(int n, int k, vector<int> v) {
    ll hp = v[k], s = 0, mn = 0;
    deque<array<ll, 3>> pre;
    for (int i = k - 1; i >= 0; --i) {
        s += v[i];
        mn = min(mn, s);
        if (s > 0) {
            pre.push_back({i, s, mn});
            s = mn = 0;
        }
    }
    for (int i = k + 1; i < n; ++i) {
        while (!pre.empty() && pre[0][2] + hp >= 0) {
            hp += pre[0][1];
            pre.pop_front();
        }
        if (hp + v[i] < 0)
            return false;
        hp += v[i];
    }
    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n), w(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        w[n - 1 - i] = v[i];
    }
    if (solve_case(n, k - 1, v) || solve_case(n, n - k, w))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}