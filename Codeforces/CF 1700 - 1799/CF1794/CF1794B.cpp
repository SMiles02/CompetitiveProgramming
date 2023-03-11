#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1)
            ++a[i];
    }
    cout << a[0] << " ";
    for (int i = 1; i < n; ++i) {
        if (a[i] % a[i - 1] == 0)
            ++a[i];
        cout << a[i] << " ";
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