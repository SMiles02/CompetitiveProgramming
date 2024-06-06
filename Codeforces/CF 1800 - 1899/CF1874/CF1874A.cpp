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
    int n, m, x;
    cin >> n >> m >> x;
    deque<int> v, w;
    for (int i = 0, k; i < n; ++i) {
        cin >> k;
        v.push_back(k);
    }
    for (int i = 0, k; i < m; ++i) {
        cin >> k;
        w.push_back(k);
    }
    for (int i = 1; i <= min(x, 50 + (x & 1)); ++i) {
        sort(v.begin(), v.end());
        sort(w.begin(), w.end());
        if (i & 1) {
            if (v[0] < w.back()) {
                int x = v[0], y = w.back();
                v.pop_front();
                w.pop_back();
                v.push_back(y);
                w.push_back(x);
            }
        }
        else {
            if (w[0] < v.back()) {
                int x = w[0], y = v.back();
                w.pop_front();
                v.pop_back();
                w.push_back(y);
                v.push_back(x);
            }
        }
    }
    ll sum = 0;
    for (int i : v) {
        sum += i;
    }
    cout << sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}