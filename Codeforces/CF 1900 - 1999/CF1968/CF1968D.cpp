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
    int n, k, x, y, pos;
    cin >> n >> k >> x >> y;
    ll ansa = 0, ansb = 0, cur;
    vector<int> a(n + 1), p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    pos = x;
    cur = 0;
    for (int i = 0; i < min(n, k); ++i) {
        cur += a[pos];
        ansa = max(ansa, cur + 1LL * a[pos] * (k - i - 1));
        pos = p[pos];
    }
    pos = y;
    cur = 0;
    for (int i = 0; i < min(n, k); ++i) {
        cur += a[pos];
        ansb = max(ansb, cur + 1LL * a[pos] * (k - i - 1));
        pos = p[pos];
    }
    if (ansa > ansb) {
        cout << "Bodya\n";
    }
    else if (ansa < ansb) {
        cout << "Sasha\n";
    }
    else {
        cout << "Draw\n";
    }
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