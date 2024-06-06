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
    int n, m;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &i : a) {
        cin >> i;
    }
    for (int &i : b) {
        cin >> i;
    }
    cin >> m;
    vector<int> d(m);
    map<int, int> mp;
    for (int &i : d) {
        cin >> i;
        ++mp[i];
    }
    bool found = false;
    for (int i : b) {
        found |= i == d[m - 1];
    }
    if (!found) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            if (mp[b[i]]-- == 0) {
                cout << "NO\n";
                return;
            }
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