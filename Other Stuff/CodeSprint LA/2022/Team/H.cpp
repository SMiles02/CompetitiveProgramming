#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5 + 1;
ll ans = 0;
int n, m, x, y, sub[N];
string s, t;
vector<int> e[N];

void subDfs(int c, int p) {
    sub[c] = 1;
    for (int i : e[c])
        if (i != p) {
            subDfs(i, c);
            sub[c] += sub[i];
        }
}

int calc(int c, int p) {
    if (sub[c] < sub[p])
        return sub[c];
    return n - sub[p];
}

void dfs(int c, int p, int l) {
    if (l == m) {
        ans += calc(c, p);
        return;
    }
    // cout << c << " " << p << " " << l << "\n";
    // cout << e[c].size() << "\n";
    for (int i : e[c])
        if (i != p) {
            // cout << c << " " << i << " " << s[i - 1] << " " << t[l] << "\n";
            if (s[i - 1] > t[l])
                ans += calc(i, c);
            else if (s[i - 1] == t[l])
                dfs(i, c, l + 1);
        }
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    cin >> s;
    cin >> t;
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    subDfs(1, 0);
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] > t[0])
            ans += n;
        else if (s[i - 1] == t[0]) {
            dfs(i, 0, 1);
        }
        // cerr << ans << "\n";
    }
    cout << ans;
    return 0;
}