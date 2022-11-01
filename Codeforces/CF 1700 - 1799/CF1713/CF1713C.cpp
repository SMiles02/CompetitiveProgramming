#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, s;
    cin >> n;
    vector<int> ans(n);
    x = n - 1;
    while (x >= 0) {
        s = sqrt(x * 2);
        while (s * s - x > x)
            --s;
        for (int i = s * s - x; i <= x; ++i)
            ans[i] = s * s - i;
        x = s * s - x - 1;
    }
    for (int i : ans)
        cout << i << " ";
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