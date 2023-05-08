#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "-1\n";
        return;
    }
    vector<int> ans;
    while (n > 1) {
        if (((n + 1) / 2) & 1) {
            ans.push_back(1);
            n = (n + 1) / 2;
        }
        else {
            ans.push_back(2);
            n /= 2;
        }
    }
    cout << ans.size() << "\n";
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
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