#include <bits/stdc++.h>
using namespace std;

bool leq(array<int, 2> a, array<int, 2> b) {
    return a <= b;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, q, cnt = 0, good = 0, x = -1, y = 0, a, b;
    cin >> n >> m >> q;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < m; ++j)
            cnt += (s[i][j] == '*');
    }
    for (int i = 0; i < cnt; ++i) {
        ++x;
        if (x == n) {
            ++y;
            x = 0;
        }
        good += (s[x][y]  == '*');
    }
    while (q--) {
        cin >> a >> b;
        --a;
        --b;
        if (s[a][b] == '.') {
            s[a][b] = '*';
            ++cnt;
            good += leq({b, a}, {y, x});
            ++x;
            if (x == n) {
                ++y;
                x = 0;
            }
            good += (s[x][y] == '*');
        }
        else {
            s[a][b] = '.';
            --cnt;
            good -= leq({b, a}, {y, x});
            good -= (s[x][y] == '*');
            --x;
            if (x == -1) {
                --y;
                x = n - 1;
            }
        }
        cout << cnt - good << "\n";
    }
    return 0;
}