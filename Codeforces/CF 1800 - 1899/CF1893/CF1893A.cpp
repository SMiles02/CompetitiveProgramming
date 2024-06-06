#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5 + 1;
int to[N];
vector<int> from[N];

void add_edge(int x, int y) {
    // cout << x << " " << y << "\n";
    from[x].push_back(y);
    ++to[y];
}

void solve() {
    int n, k, d = 0;
    cin >> n >> k;
    vector<int> dp(n), v;
    for (int i = 0, bi; i < n; ++i) {
        cin >> bi;
        --bi;
        if (bi >= n) {
            continue;
        }
        add_edge((i - bi + n) % n, (i + 1) % n);
    }
    for (int i = 0; i < n; ++i) {
        if (to[i] == 0) {
            v.push_back(i);
        }
    }
    while (!v.empty()) {
        ++d;
        int x = v.back();
        v.pop_back();
        for (int y : from[x]) {
            dp[y] = max(dp[y], dp[x] + 1);
            if (--to[y] == 0) {
                v.push_back(y);
            }
        }
        if (dp[x] >= k) {
            cout << "YES\n";
            return;
        }
    }
    if (d < n) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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