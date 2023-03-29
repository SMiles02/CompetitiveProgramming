#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] != '0' && s[i] != '1') {
            char c;
            if (i & 1)
                c = '1';
            else
                c = '0';
            for (int j = n - 1; j >= i; --j)
                if (s[i] == s[j])
                    s[j] = c;
        }
        else if (((i & 1) && s[i] == '0') || (((i & 1) & 1) == 0 && s[i] == '1')) {
            cout << "NO\n";
            return;
        } 
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}