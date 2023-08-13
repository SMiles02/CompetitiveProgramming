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
    string s, t;
    cin >> s;
    cin >> t;
    vector<int> f(26);
    for (auto i : s) {
        ++f[i - 'a'];
    }
    if (t != "abc" || min({f[0], f[1], f[2]}) == 0) {
        sort(s.begin(), s.end());
        cout << s << "\n";
        return;
    }
    while (f[0]--) {
        cout << "a";
    }
    while (f[2]--) {
        cout << "c";
    }
    while (f[1]--) {
        cout << "b";
    }
    for (int i = 3; i < 26; ++i) {
        while (f[i]--) {
            cout << (char)('a' + i);
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}