#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e5 + 3;
bitset<N> leaf;
vector<int> e[N];

void dfs(int c, int p) {
    bool cd = false;
    for (int i : e[c]) {
        if (i == p) {
            continue;
        }
        dfs(i, c);
        cd = true;
    }
    if (!cd) {
        leaf[c] = 1;
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
        leaf[i] = 0;
    }
    for (int i = 1, x, y; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    string s;
    cin >> s;
    dfs(1, 0);
    int x = 0, y = 0, z = 0, o = 0;
    for (int i = 2; i <= n; ++i) {
        if (leaf[i] == 0) {
            o += s[i - 1] == '?';
            continue;
        }
        x += s[i - 1] == '0';
        y += s[i - 1] == '1';
        z += s[i - 1] == '?';
    }
    if (s[0] == '0') {
        cout << y + (z + 1) / 2 << "\n";
    }
    else if (s[0] == '1') {
        cout << x + (z + 1) / 2 << "\n";
    }
    else {
        int ans;
        if (x == y) {
            if (o & 1) {
                ans = max(x, y) + (z + 1) / 2;
            }
            else {
                ans = max(x, y) + z / 2;
            }
        }
        else if (abs(x - y) == 1) {
            ans = max(x, y) + z / 2;
        }
        else {
            ans = max(x + z / 2, y + z / 2);
        }
        cout << ans << "\n";
    }
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