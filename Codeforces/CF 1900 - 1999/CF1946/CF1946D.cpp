#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1), p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = p[i - 1] ^ a[i];
    }
    if (p[n] > x) {
        cout << "-1\n";
        return;
    }
    cout << "69\n";
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