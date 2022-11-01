#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b;
    cin >> n;
    vector<int> x = {0}, y = {0};
    while (n--) {
        cin >> a >> b;
        if (a == 0)
            x.push_back(b);
        else
            y.push_back(a);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    cout << (x.back() - x.front() + y.back() - y.front()) * 2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}