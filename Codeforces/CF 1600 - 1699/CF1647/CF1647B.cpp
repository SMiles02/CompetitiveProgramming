#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

void solve() {
    int n, m, x, y, cnt, r;
    cin >> n >> m;
    vector<string> s(n + 2, string(m + 2, '0'));
    vector<vector<bool>> dn(n + 2, vector<bool>(m + 2));
    bool ok = true;
    string tmp;
    for (int i = 1; i <= n; ++i) {
        cin >> tmp;
        for (int j = 1; j <= m; ++j)
            s[i][j] = tmp[j - 1];
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (s[i][j] == '1' && !dn[i][j] && ok) {
                x = j;
                y = j;
                while (s[i][y + 1] == '1')
                    ++y;
                cnt = y - x + 1;
                r = i;
                // cout << r << " " << x << " " << y << "\n";
                while (cnt == y - x + 1 && ok) {
                    for (int k = x; k <= y; ++k)
                        dn[r][k] = true;
                    ++r;
                    cnt = 0;
                    for (int k = x; k <= y; ++k)
                        cnt += (s[r][k] == '1');
                    if ((0 < cnt && cnt < y - x + 1) || (cnt == y - x + 1 && (s[r][x - 1] == '1' || s[r][y + 1] == '1')))
                        ok = false;
                }
                // cout << r << " " << ok << "\n";
            }
    if (ok)
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