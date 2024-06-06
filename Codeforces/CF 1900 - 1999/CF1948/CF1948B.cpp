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
    vector<int> v(n), w = {100};
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        if (v[i] <= w.back()) {
            w.push_back(v[i]);
        }
        else if (v[i] > 9 && v[i] / 10 <= v[i] % 10 && v[i] % 10 <= w.back()) {
            w.push_back(v[i] / 10);
        }
        else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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