#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n), v; 
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
        a[i][1] = i + 1;
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < n; ++i) {
        if (a[i - 1][0] >= a[i][0]) {
            v.push_back({a[i][1], a[i - 1][0] - a[i][0]});
            a[i] = a[i - 1];
        }
        else if (a[i][0] % a[i - 1][0]) {
            v.push_back({a[i][1], a[i - 1][0] - (a[i][0] % a[i - 1][0])});
            a[i][0] += a[i - 1][0] - (a[i][0] % a[i - 1][0]);
        }
    }
    cout << v.size() << "\n";
    for (auto i : v)
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