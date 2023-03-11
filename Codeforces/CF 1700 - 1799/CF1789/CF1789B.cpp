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
    int n, l = -1, r = -1, x;
    cin >> n;
    string s;
    cin >> s;
    vector<bool> b(n);
    for (int i = 0; i < n - i - 1; ++i)
        if (s[i] != s[n - i - 1]) {
            r = i;
            if (l == -1)
                l = i;
        }
    if (l == -1) {
        cout << "YES\n";
        return;
    }
    x = r;
    for (int i = l; i <= x; ++i)
        if (s[i] == s[n - i - 1])
            r = max(r, n - i - 1);
    for (int i = l; i <= r; ++i) {
        if (s[i] == '0')
            s[i] = '1';
        else
            s[i] = '0';
    }
    for (int i = 0; i < n; ++i)
        if (s[i] != s[n - i - 1]) {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}