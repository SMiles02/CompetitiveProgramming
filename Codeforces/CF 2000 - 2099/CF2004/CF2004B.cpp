#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;
    if (b < c || d < a) {
        cout << "1\n";
    }
    else {
        cout << min(b, d) - max(a, c) + (a != c) + (b != d) << "\n";
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