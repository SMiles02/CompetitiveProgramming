#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);
    for (int i = n; i > 0; --i)
        for (int j = 0; j < i && k < (n * (n + 1)) / 2; ++j, ++k)
            swap(p[j], p[j + 1]);
    for (int i = 0; i < n; ++i)
        cout << p[i + 1] - p[i] << " ";
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