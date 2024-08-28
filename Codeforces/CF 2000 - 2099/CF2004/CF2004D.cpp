#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5 + 5, INF = 1e8;
int ans;
string s[N];
vector<int> m[N][2];

void solve() {
    int n, q;
    cin >> n >> q;
    map<char, char> mp;
    mp['R'] = '0';
    mp['G'] = '1';
    mp['B'] = '2';
    mp['Y'] = '3';
    vector<int> val(n + 1), last(13);
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        // cout << mp[s[i][0]] << " " << mp[s[i][1]] << "\n";
        string t = "";
        t += mp[s[i][0]];
        t += mp[s[i][1]];
        s[i] = t;
        val[i] = (1 << (s[i][0] - '0')) + (1 << (s[i][1] - '0'));
    }
    last = vector<int>(13, -INF);
    for (int i = 1; i <= n; ++i) {
        last[val[i]] = i;
        m[i][0] = last;
    }
    last = vector<int>(13, INF);
    for (int i = n; i >= 1; --i) {
        last[val[i]] = i;
        m[i][1] = last;
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (val[x] & val[y]) {
            cout << abs(x - y) << "\n";
            continue;
        }
        ans = 1e8;
        for (int j = 1; j < 13; ++j) {
            if (j != val[x] && j != val[y]) {
                ans = min(ans, abs(m[x][0][j] - x) + abs(m[x][0][j] - y));
                ans = min(ans, abs(m[x][1][j] - x) + abs(m[x][1][j] - y));
                // cout << j << ": " << ans << "\n";
            }
        }
        if (ans == 1e8) {
            ans = -1;
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