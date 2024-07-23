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

const long long INF = 1e15;

void solve() {
    int n;
    cin >> n;
    long long ans = 0;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        long long l = 0, r = INF, m;
        while (l < r) {
            m = l + (r - l) / 2;
            if ((double)b[i - 1] + log2(log2(a[i - 1])) <= (double)m + log2(log2(a[i]))) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        if (l == INF) {
            cout << "-1\n";
            return;
        }
        ans += l;
        b[i] = l;
    }
    cout << ans << "\n";
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