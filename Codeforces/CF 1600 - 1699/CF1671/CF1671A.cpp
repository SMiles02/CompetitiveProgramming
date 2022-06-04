#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    vector<int> v = {1};
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1])
            ++v.back();
        else
            v.push_back(1);
    }
    for (int i : v)
        if (i == 1) {
            cout << "NO\n";
            return;
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