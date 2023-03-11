#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    bool f = false, r = false;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (auto j : s[i]) {
            f |= j == 'F';
            r |= j == 'R';
        }
    }
    cout << 0 + f + r;
    return 0;
}