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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<vector<int>> w(31);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        w[__lg(a[i] & -a[i])].push_back(i);
    }
    while (q--) {
        int p;
        cin >> p;
        for (int i = p; i < 31; ++i) {
            while (!w[i].empty()) {
                a[w[i].back()] += 1 << (p - 1);
                w[p - 1].push_back(w[i].back());
                w[i].pop_back();
            }
        }
    }
    for (int i : a) {
        cout << i << " ";
    }
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