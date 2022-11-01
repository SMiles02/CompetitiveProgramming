#include <bits/stdc++.h>
using namespace std;

const int N = 51;
int n, m;
string s[N];
bool ok;

bool in_range(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < m);
}

bool check(int x, int y) {
    if (0 <= x && x < n && 0 <= y && y < m && s[x][y] != '.')
        ok = false;
}

void solve() {
    cin >> n >> m;
    // garbage problem
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = 0; i + 1 < n; ++i)
        for (int j = 0; j + 1 < m; ++j) {
            int cnt = 0;
            for (int k = 0; k < 2; ++k)
                for (int l = 0; l < 2; ++l)
                    cnt += (s[i + k][j + l] == '*');
            if (cnt == 3) {
                ok = true;
                for (int k = 0; k < 2; ++k)
                    for (int l = 0; l < 2; ++l)
                        if (s[i + k][j + l] == '*')
                            for (int x = -1; x < 2; ++x)
                                for (int y = -1; y < 2; ++y)
                                    if (in_range(i + k + x, j + l + y) && !(i <= i + k + x && i + k + x <= i + 1 && j <= j + l + y && j + l + y <= j + 1))
                                        check(i + k + x, j + l + y);
                if (ok)
                    for (int k = 0; k < 2; ++k)
                        for (int l = 0; l < 2; ++l)
                            if (s[i + k][j + l] == '*')
                                s[i + k][j + l] = '?';
            }
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (s[i][j] == '*') {
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