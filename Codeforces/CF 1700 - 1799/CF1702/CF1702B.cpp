#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size(), cur = 0, ans = 0;
    while (cur < n) {
        set<char> st;
        ++ans;
        while (cur < n) {
            st.insert(s[cur]);
            if (st.size() > 3)
                break;
            ++cur;
        }
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