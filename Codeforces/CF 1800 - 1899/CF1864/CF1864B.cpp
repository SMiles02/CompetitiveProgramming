#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k & 1) {
        vector<string> a(2, "");
        for (int i = 0; i < n; ++i) {
            a[i & 1] += s[i];
        }
        sort(a[0].begin(), a[0].end());
        sort(a[1].begin(), a[1].end());
        for (int i = 0; i < n; ++i) {
            cout << a[i & 1][i / 2];
        }
        cout << "\n";
    }
    else {
        sort(s.begin(), s.end());
        cout << s << "\n";
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