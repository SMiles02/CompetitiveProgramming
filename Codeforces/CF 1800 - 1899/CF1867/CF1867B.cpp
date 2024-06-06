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
    int n, cnt = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n - i - 1; ++i) {
        cnt += s[i] != s[n - i - 1];
    }
    for (int i = 0; i <= n; ++i) {
        bool ok = false;
        if (i >= cnt) {
            if (i <= n - cnt && (cnt % 2 == i % 2 || n % 2 == 1)) {
                ok = true;
            }
        }
        cout << ok;
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