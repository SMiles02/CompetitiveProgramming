#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int min_factor(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return i;
        }
    }
    return n;
}

void solve() {
    int a, b;
    cin >> a >> b;
    if (a == 1) {
        cout << 1LL * b * b << "\n";
    }
    else {
        if (b % a == 0) {
            cout << 1LL * b * (b / a) << "\n";
        }
        else {
            cout << 1LL * b * min_factor(a) << "\n";
        }
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