#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n & 1) {
        cout << "Yes\n";
        for (int i = n * 2 + 1 - n / 2, j = 1 + n / 2; i <= n * 2 + 1; ++i, --j) {
            cout << j << " " << i - j << "\n";
        }
        for (int i = n * 2 + 2, j = n; i <= n * 2 + 1 + n / 2; ++i, --j)
            cout << j << " " << i - j << "\n";
    }
    else
        cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}