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
    if (s[0] == t[0]) {
        cout << "YES\n" << s[0] << "*\n";
        return;
    }
    else if (s.back() == t.back()) {
        cout << "YES\n*" << s.back() << "\n";
        return;
    }
    for (int i = 1; i < s.size(); ++i)
        for (int j = 1; j < t.size(); ++j)
            if (s[i - 1] == t[j - 1] && s[i] == t[j]) {
                cout << "YES\n*" << s[i - 1] << s[i] << "*\n";
                return;
            }
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