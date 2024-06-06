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
    string s, t = "";
    cin >> s;
    vector<int> num(26);
    vector<bool> f(26);
    for (auto i : s) {
        f[i - 'a'] = true;
    }
    for (int i = 0; i < 26; ++i) {
        if (f[i]) {
            num[i] = t.size();
            t += ('a' + i);
        }
    }
    for (auto i : s) {
        cout << t[t.size() - 1 - num[i - 'a']];
    }
    cout << "\n";
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