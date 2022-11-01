#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    deque<array<int, 2>> ans;
    for (int i = n; i >= 1; --i)
        if (a[i] % 2 == a[1] % 2) {
            x = i;
            break;
        }
    for (int i = n; i >= 1; --i)
        if (i != x) {
            if (a[i] % 2 == a[1] % 2)
                ans.push_front({i, x});
            else
                ans.push_back({1, i});
        }
    cout << n - 1 << "\n";
    for (auto i : ans)
        cout << i[0] << " " << i[1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}