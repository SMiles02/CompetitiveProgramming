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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> active(m + 1);
    vector<ll> ans(m + 1);
    while (k--) {
        int p, c;
        cin >> c >> p;
        if (active[p]) {
            if (active[p] == c) {
                ans[p] += 100;
            }
            else {
                ans[p] += abs(c - active[p]);
            }
            active[p] = 0;
        }
        else {
            active[p] = c;
        }
        // cout << p << " " << ans[p] << "\n";
    }
    for (int i = 1; i <= m; ++i) {
        cout << ans[i] + 100 * (active[i] != 0) << " ";
    }
    return 0;
}