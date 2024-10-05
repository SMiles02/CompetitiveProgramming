#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a == 0) {
        if (b & 1) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
    else if (a & 1) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
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