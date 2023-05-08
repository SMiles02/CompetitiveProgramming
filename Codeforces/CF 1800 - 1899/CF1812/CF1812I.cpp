#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

map<char, int> m;
string asc = "tdfhklb", desc = "qypgj";

void solve() {
    int score = 0;
    bool ok = true;
    string s;
    cin >> s;
    for (auto i : s)
        ok &= ((score += m[i]) >= 0);
    ok &= score == 0;
    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (auto i : asc)
        ++m[i];
    for (auto i : desc)
        --m[i];
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}