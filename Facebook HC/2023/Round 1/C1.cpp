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
    int n, q, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    cin >> q;
    vector<int> v(n + 1);
    while (q--) {
        int k;
        cin >> k;
        v[k] ^= 1;
    }
    for (int i = n; i >= 1; --i) {
        if (v[i]) {
            for (int j = i * 2; j <= n; j += i) {
                v[j] ^= 1;
            }
        }
        v[i] ^= s[i - 1] == '1';
    }
    for (int i = 1; i <= n; ++i) {
        if (v[i]) {
            ++ans;
            for (int j = i; j <= n; j += i) {
                v[j] ^= 1;
            }
        }
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