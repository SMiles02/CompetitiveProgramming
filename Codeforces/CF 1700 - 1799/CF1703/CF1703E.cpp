#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = 0, x, y;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    vector<vector<bool>> done(n, vector<bool>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (!done[i][j]) {
                set<array<int, 2>> st;
                x = i;
                y = j;
                for (int k = 0; k < 4; ++k) {
                    st.insert({x, y});
                    swap(x, y);
                    y = n - 1 - y;
                }
                vector<int> cnt(2);
                for (auto k : st) {
                    done[k[0]][k[1]] = true;
                    ++cnt[s[k[0]][k[1]] - '0'];
                }
                ans += min(cnt[0], cnt[1]);
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