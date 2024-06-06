#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5 + 4;
int col[N];
ll ans;
vector<int> e[N];

ll f(int x) {
    return (1LL * x * (x - 1)) / 2;
}

map<int, int> dfs(int c, int p) {
    map<int, int> cur;
    for (int i : e[c]) {
        if (i == p) {
            continue;
        }
        map<int, int> tmp = dfs(i, c);
        ans += f(tmp[col[c]]) + tmp[col[c]];
        tmp[col[c]] = 0;
        if (cur.size() < tmp.size()) {
            swap(cur, tmp);
        }
        for (auto i : tmp) {
            cur[i.first] += i.second;
        }
    }
    cur[col[c]] = 1;
    // cerr << c << ": " << ans << "\n";
    // for (auto i : cur) {
    //     cerr << i.first << " - " << i.second << "\n";
    // }
    return cur;
}

void solve() {
    int n;
    cin >> n;
    ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> col[i];
        e[i].clear();
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    map<int, int> m = dfs(1, 0);
    for (auto i : m) {
        ans += f(i.second);
    }
    cout << ans << "\n";
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