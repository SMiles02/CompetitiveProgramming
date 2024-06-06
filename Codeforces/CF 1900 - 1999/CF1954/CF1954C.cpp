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
    bool same = true;
    for (int i = 0; i < s.size(); ++i) {
        if (same) {
            if (s[i] != t[i]) {
                if (s[i] > t[i]) {
                    swap(s[i], t[i]);
                }
                same = false;
            }
        }
        else {
            if (s[i] < t[i]) {
                swap(s[i], t[i]);
            }
        }
    }
    cout << s << "\n" << t << "\n";
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