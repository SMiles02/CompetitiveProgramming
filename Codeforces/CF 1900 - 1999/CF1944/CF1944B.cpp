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
    vector<int> a(n * 2), x, y, z, p, q;
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < n * 2; ++i) {
        cin >> a[i];
        v[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (v[i][1] < n) {
            x.push_back(i);
        }
        else if (n <= v[i][0]) {
            y.push_back(i);
        }
        else {
            z.push_back(i);
        }
    }
    while (p.size() + 2 <= k * 2 && !x.empty()) {
        p.push_back(x.back());
        p.push_back(x.back());
        x.pop_back();
        q.push_back(y.back());
        q.push_back(y.back());
        y.pop_back();
    }
    while (p.size() + 1 <= k * 2 && !z.empty()) {
        p.push_back(z.back());
        q.push_back(z.back());
        z.pop_back();
    }
    for (int i : p) {
        cout << i << " ";
    }
    cout << "\n";
    for (int i : q) {
        cout << i << " ";
    }
    cout << "\n";
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