#include <bits/stdc++.h>
using namespace std;

string s[8];

int cnt(int x) {
    int ret = 0;
    for (int i = 0; i < 8; ++i)
        ret += (s[x][i] == '#');
    return ret;
}

void solve() {
    bool ok = false;
    for (int i = 0; i < 8; ++i)
        cin >> s[i];
    for (int i = 0; i < 8; ++i) {
        if (cnt(i) == 2)
            ok = true;
        else if (ok && cnt(i) == 1) {
            for (int j = 0; j < 8; ++j)
                if (s[i][j] == '#') {
                    cout << i + 1 << " " << j + 1 << "\n";
                    return;
                }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}