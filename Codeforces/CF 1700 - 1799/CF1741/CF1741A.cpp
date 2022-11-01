#include <bits/stdc++.h>
using namespace std;

int score(string s) {
    if (s == "M")
        return 0;
    if (s.back() == 'L')
        return s.size();
    return -1 * s.size();
}

void solve() {
    string s, t;
    cin >> s >> t;
    int x = score(s), y = score(t);
    if (x > y)
        cout << ">\n";
    else if (x < y)
        cout << "<\n";
    else
        cout << "=\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}