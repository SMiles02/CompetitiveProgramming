#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, ans=0;
    cin >> n;
    map<int,int> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        if (!m[x])
            m[x] = 1;
        else if (!m[-x])
            m[-x] = 1;
        else
            continue;
        ++ans;
    }
    cout << ans << "\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}