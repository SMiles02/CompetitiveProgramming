#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int q, d, k;
    cin >> q;
    vector<vector<ll>> v(2, vector<ll>(26));
    vector<int> n(2, 1);
    string x;
    v[0][0] = v[1][0] = 1;
    while (q--) {
        cin >> d >> k >> x;
        for (auto i : x)
            v[d - 1][i - 'a'] += k;
        bool ans = true;
        for (int i = 0; i < 26; ++i)
            if (v[0][i] > v[1][i])
                ans = false;
        ans &= (v[0] != v[1]);
        for (int j = 1; j < 26; ++j)
            if (v[1][j])
                ans = true;
        if (ans)
            cout << "YES\n";
        else
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