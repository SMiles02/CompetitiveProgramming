#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, j = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i < n; ++i)
        if (s[i] <= s[j])
            j = i;
    cout << s[j];
    for (int i = 0; i < j; ++i)
        cout << s[i];
    for (int i = j + 1; i < n; ++i)
        cout << s[i];
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