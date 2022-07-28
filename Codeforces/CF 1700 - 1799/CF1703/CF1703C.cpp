#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i) {
        int k;
        string s;
        cin >> k;
        if (k == 0)
            continue;
        cin >> s;
        for (auto j : s) {
            if (j == 'D')
                ++a[i];
            else
                a[i] += 9;
        }
        cout << a[i] % 10 << " ";
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