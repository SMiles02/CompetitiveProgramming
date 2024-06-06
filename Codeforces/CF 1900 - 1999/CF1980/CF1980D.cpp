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
    int n;
    cin >> n;
    vector<int> a(n + 2);
    vector<bool> p(n + 2, true), s(n + 2, true);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 3; i <= n; ++i) {
        p[i] = p[i - 1] & (__gcd(a[i - 2], a[i - 1]) <= __gcd(a[i - 1], a[i]));
    }
    for (int i = n - 2; i > 0; --i) {
        s[i] = s[i + 1] & (__gcd(a[i], a[i + 1]) <= __gcd(a[i + 1], a[i + 2]));
    }
    if (p[n - 1] || s[2]) {
        cout << "YES\n";
        return;
    }
    for (int i = 2; i < n; ++i) {
        if (p[i - 1] && s[i + 1] && (i == 2 || __gcd(a[i - 2], a[i - 1]) <= __gcd(a[i - 1], a[i + 1])) && (i == n - 1 || __gcd(a[i - 1], a[i + 1]) <= __gcd(a[i + 1], a[i + 2]))) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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