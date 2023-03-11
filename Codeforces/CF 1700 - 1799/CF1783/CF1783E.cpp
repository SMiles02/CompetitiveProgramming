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
    int n, l = 0;
    cin >> n;
    int a[n], b[n];
    vector<bool> ok(n + 1, true);
    vector<int> p(n + 1);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (a[i] > b[i]) {
            ++p[b[i]];
            --p[a[i]];
            l = max(l, a[i] - b[i]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        p[i] += p[i - 1];
        if (p[i])
            for (int j = 1; j * j <= i; ++j)
                if (i % j == 0) {
                    ok[j] = false;
                    ok[i / j] = false;
                }
    }
    vector<int> ans;
    for (int i = l + 1; i <= n; ++i)
        if (ok[i])
            ans.push_back(i);
    cout << ans.size() << "\n";
    for (int i : ans)
        cout << i << " ";
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