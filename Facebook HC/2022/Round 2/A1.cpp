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

const int N = 1e6 + 1;
int p[N][26];

vector<int> query(int l, int r) {
    vector<int> v(26);
    for (int i = 0; i < 26; ++i)
        v[i] = p[r][i] - p[l - 1][i];
    return v;
}

bool works(int l, int m1, int r) {
    int m2 = m1 + 1;
    if (m1 - l < r - m2) {
        swap(l, m2);
        swap(m1, r);
    }
    vector<int> v = query(l, m1), w = query(m2, r);
    bool dn = false;
    for (int i = 0; i < 26; ++i) {
        if (v[i] == w[i] + 1) {
            if (dn)
                return false;
            dn = true;
        }
        else if (v[i] != w[i])
            return false;
    }
    return true;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size(), q, l, r, ans = 0;
    cin >> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j)
            p[i + 1][j] = p[i][j];
        ++p[i + 1][s[i] - 'a'];
    }
    while (q--) {
        cin >> l >> r;
        if ((r - l) & 1)
            continue;
        if (l == r) {
            ++ans;
            continue;
        }
        if (works(l, l + (r - l) / 2 - 1, r) || works(l, l + (r - l) / 2, r))
            ++ans;
    }
    cout << ans << "\n";
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