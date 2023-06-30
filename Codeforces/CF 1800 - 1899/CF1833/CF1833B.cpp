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
    int n, k;
    cin >> n >> k;
    vector<array<int, 2>> v(n), w(n);
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i][0];
        v[i][1] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> w[i][0];
        w[i][1] = i;
    }
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    for (int i = 0; i < n; ++i)
        ans[v[i][1]] = w[i][0];
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