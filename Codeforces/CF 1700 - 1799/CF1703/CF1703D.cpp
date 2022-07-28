#include <bits/stdc++.h>
using namespace std;

string sub(string s, int l, int r) {
    string ans = "";
    for (int i = l; i <= r; ++i)
        ans += s[i];
    return ans;
}

void solve() {
    int n, k;
    cin >> n;
    set<string> st;
    string s[n];
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        st.insert(s[i]);
    }
    for (int i = 0; i < n; ++i) {
        bool found = false;
        k = s[i].size();
        for (int j = 0; j + 1 < k; ++j)
            found |= (st.count(sub(s[i], 0, j)) && st.count(sub(s[i], j + 1, k - 1)));
        if (found)
            cout << 1;
        else
            cout << 0;
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