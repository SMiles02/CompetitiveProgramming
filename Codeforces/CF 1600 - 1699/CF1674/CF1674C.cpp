#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    cin >> s;
    cin >> t;
    if (t == "a") {
        cout << "1\n";
        return;
    }
    for (auto i : t)
        if (i == 'a') {
            cout << "-1\n";
            return;
        }
    cout << (1LL << s.size()) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}