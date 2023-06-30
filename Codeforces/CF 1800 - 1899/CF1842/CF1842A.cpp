#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m;
    long long sum = 0;
    while (n--) {
        cin >> k;
        sum += k;
    }
    while (m--) {
        cin >> k;
        sum -= k;
    }
    if (sum > 0)
        cout << "Tsondu\n";
    else if (sum < 0)
        cout << "Tenzing\n";
    else
        cout << "Draw\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}