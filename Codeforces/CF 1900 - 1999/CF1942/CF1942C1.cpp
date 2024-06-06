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
    int n, x, y, cnt;
    cin >> n >> x >> y;
    vector<int> v(x);
    for (int i = 0; i < x; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cnt = x;
    for (int i = 1; i < x; ++i) {
        cnt += v[i - 1] + 2 == v[i];
    }
    cnt += v[x - 1] == n - 1 && v[0] == 1;
    cnt += v[x - 1] == n && v[0] == 2;
    cout << max(cnt - 2, 0) << "\n";
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