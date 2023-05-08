#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;
    bool done = false;
    for (int i = 0; i < n; ++i) {
        if ((s[i] - '0') >= d)
            cout << s[i];
        else {
            cout << d;
            for (int j = i; j < n; ++j)
                cout << s[j];
            done = true;
            break;
        }
    }
    if (!done)
        cout << d;
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