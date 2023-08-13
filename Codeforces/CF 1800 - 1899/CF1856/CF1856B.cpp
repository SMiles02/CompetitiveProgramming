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
    int n;
    cin >> n;
    int a[n];
    ll sum = 0;
    map<int, int> m;
    array<int, 2> f = {-1, -1};
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        f = max(f, {++m[a[i]], a[i]});
    }
    if (n == 1) {
        cout << "NO\n";
    }
    else if (f[0] * 2 <= n || n + m[1] <= sum) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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