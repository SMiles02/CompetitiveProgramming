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
    int n;
    cin >> n;
    string s, t;
    cin >> s;
    cin >> t;
    bool a = 0, b = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        a |= (s[i] == t[i]);
        b |= (s[i] != t[i]);
    }
    if (a & b) {
        cout << "NO\n";
        return;
    }
    if (b)
        c = 1;
    cout << "YES\n";
    vector<array<int, 2>> ans;
    for (int i = 1; i < n; ++i)
        if (s[i] != s[i - 1]) {
            ans.push_back({1, i});
            c = 1 - c;
        }
    if (c == 0) { // all same
        if (s[n - 1] == '1') {
            ans.push_back({1, 1});
            ans.push_back({2, n});
        }
    }
    else {
        if (s[n - 1] == '0') {
            ans.push_back({1, n});
            ans.push_back({1, 1});
            ans.push_back({2, n});
        }
        else {
            ans.push_back({1, n});
        }
    }
    cout << ans.size() << "\n";
    for (auto i : ans)
        cout << i[0] << " " << i[1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}