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
    int n, k, ans = 0;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int l = 0; l < n; ++l) {
        int sm = 0;
        for (int r = l; r < n; ++r) {
            sm += a[r];
            ans += (sm > 0);
            if (sm == 0) {
                cout << "Zero at " << n << " " << k << ": " << l << "  " << r << "\n";
                return;
            }
        }
    }
    if (ans != k) {
        cout << "Nope at " << n << " " << k << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}