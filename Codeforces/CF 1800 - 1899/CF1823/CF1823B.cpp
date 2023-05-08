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
    int n, k, cnt = 0;
    cin >> n >> k;
    int a[n];
    vector<int> v(n + 1), w(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        v[a[i]] = i % k;
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
        w[a[i]] = i % k;
    for (int i = 1; i <= n; ++i)
        cnt += v[i] != w[i];
    if (cnt > 2)
        cnt = -1;
    else if (cnt == 2)
        cnt = 1;
    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}