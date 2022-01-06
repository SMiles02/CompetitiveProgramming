#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k > (n + 1) / 2)
        cout << "-1\n";
    else {
        vector<string> s(n, string(n, '.'));
        for (int i = 0; i < k; ++i)
            s[i * 2][i * 2] = 'R';
        for (auto i : s)
            cout << i << "\n";
    }
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}