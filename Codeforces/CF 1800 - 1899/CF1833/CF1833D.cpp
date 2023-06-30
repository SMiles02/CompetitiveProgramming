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
    int a[n + 1], p[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[a[i]] = i;
    }
    if (n == 1) {
        cout << "1\n";
        return;
    }
    bool unswap = false;
    if (a[1] == n) {
        unswap = true;
        swap(a[pos[n]], a[pos[n - 1]]);
        swap(pos[n], pos[n - 1]);
    }
    vector<vector<int>> v;
    v.push_back({});
    for (int )
    if (pos[n] == n) {
        
    }

    sort(v.rbegin(), v.rend());
    if (unswap) {
        vector<int> w;
        for (int i = 0; i < n; ++i)
            if (v[0][i] == n || v[0][i] == n - 1)
                w.push_back(i);
        swap(v[0][w[0]], v[0][w[1]]);
    }
    for (int i : v[0])
        cout << i << " ";
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