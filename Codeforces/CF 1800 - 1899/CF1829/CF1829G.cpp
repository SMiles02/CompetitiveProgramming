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

const int N = 1e6 + 5;
ll p[N];
vector<array<int, 3>> v;

void solve() {
    int n, l = 0, r = v.size() - 1, m;
    cin >> n;
    while (l < r) {
        m = l + (r - l) / 2 + 1;
        if (v[m][1] >= n)
            r = m - 1;
        else
            l = m;
    }
    int cur = l;
    l = r = n - v[cur][1];
    ll ans = 0;
    while (cur >= 0) {
        ans += p[v[cur][1] + r] - p[v[cur][1] + l - 1];
        if (--cur >= 0) {
            l = max(l - 1, 1);
            r = min(r, v[cur][0]);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 1; i < N; ++i)
        p[i] = p[i - 1] + 1LL * i * i;
    int cur = 0;
    for (int i = 1; cur < N; ++i) {
        v.push_back({i, cur, cur + i});
        cur += i;
    }
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}