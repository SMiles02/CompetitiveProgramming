#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int f(int n) {
    if (n % 3 == 2) {
        return n / 3;
    }
    else {
        return (n + 2) / 3;
    }
}

void solve() {
    int n, x, o = 0;
    ll s = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        s += x;
        o += x & 1;
        if (i == 0) {
            cout << s << " ";
        }
        else {
            cout << s - f(o) << " ";
        }
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