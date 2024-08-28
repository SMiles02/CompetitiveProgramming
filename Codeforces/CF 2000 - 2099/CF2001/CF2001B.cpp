#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    int n, l, r;
    cin >> n;
    if (n % 2 == 0) {
        cout << "-1\n";
        return;
    }
    vector<int> ans(n);
    l = r = (n - 1) / 2;
    ans[l] = 1;
    for (int i = 2; i <= n; ++i) {
        if (i & 1) {
            ans[--l] = i;
        }
        else {
            ans[++r] = i;
        }
    }
    for (int i : ans) {
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