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

string s = "";

void solve() {
    int n;
    cin >> n;
    string t;
    cin >> t;
    for (int i = 0; i + n <= s.size(); ++i) {
        bool ok = true;
        for (int j = 0; j < n; ++j)
            ok &= (t[j] == s[i + j]);
        if (ok) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 1; i <= 60; ++i) {
        if (i % 3 == 0)
            s += 'F';
        if (i % 5 == 0)
            s += 'B';
    }
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}