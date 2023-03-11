// @problem writer, please learn to spell 'palindromes'

#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    string s;
    cin >> s;
    vector<int> f(26);
    for (auto i : s)
        ++f[i - 'a'];
    int odds = 0;
    for (auto i : f)
        odds += i & 1;
    if (odds < 2) {
        cout << "Regular\n";
        return;
    }
    for (auto &i : s) {
        --f[i - 'a'];
        if (i == 'q')
            i = 'p';
        if (i == 'd')
            i = 'b';
        if (i == 'e')
            i = 'a';
        ++f[i - 'a'];
    }
    odds = 0;
    for (auto i : f)
        odds += i & 1;
    if (odds > 1)
        cout << "Neither\n";
    else
        cout << "Similar\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}