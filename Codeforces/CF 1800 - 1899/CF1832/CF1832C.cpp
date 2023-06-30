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
    cin >> n;
    vector<int> v;
    int a[n];
    bool same = true;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0)
            same &= a[i] == a[i - 1];
    }
    if (same) {
        cout << "1\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        k = a[i];
        if (v.size() > 1 && abs(v[v.size() - 2] - v[v.size() - 1]) + abs(v[v.size() - 1] - k) == abs(v[v.size() - 2] - k))
            v.pop_back();
        v.push_back(k);
    }
    cout << v.size() << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}