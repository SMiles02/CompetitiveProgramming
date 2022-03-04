#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = n - 1; i > 0; --i)
        if ((s[i - 1] - '0') + (s[i] - '0') > 9) {
            for (int j = 0; j < i - 1; ++j)
                cout << s[j];
            cout << (s[i - 1] - '0') + (s[i] - '0');
            for (int j = i + 1; j < n; ++j)
                cout << s[j];
            cout << "\n";
            return;
        }
    cout << (s[0] - '0') + (s[1] - '0');
    for (int i = 2; i < n; ++i)
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