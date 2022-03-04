#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long hC, dC, hM, dM, k, w, a;
    cin >> hC >> dC;
    cin >> hM >> dM;
    cin >> k >> w >> a;
    for (int i = 0; i <= k; ++i)
        if ((hM + dC + w * i - 1) / (dC + w * i) <= (hC + a * (k - i) + dM - 1) / dM) {
            cout << "YES\n";
            return;
        }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}