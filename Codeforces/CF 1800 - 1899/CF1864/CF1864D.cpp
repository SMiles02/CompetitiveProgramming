#include <bits/stdc++.h>
using namespace std;

const int N = 3003;
bitset<2> v[N][N];

void solve() {
    int n, ans = 0;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n + 3; ++i) {
        for (int j = 0; j < n + 3; ++j) {
            for (int k = 0; k < 2; ++k) {
                v[i][j][k] = 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            cur ^= v[i][j][0] ^ v[i][j][1];
            if ((s[i][j] - '0') ^ cur) {
                v[i][j][0] = v[i][j][0] ^ 1;
                v[i][j + 1][1] = v[i][j + 1][1] ^ 1;
                cur ^= 1;
                ++ans;
            }
            v[i + 1][max(j - 1, 0)][0] = v[i + 1][max(j - 1, 0)][0] ^ v[i][j][0];
            v[i + 1][j + 1][1] = v[i + 1][j + 1][1] ^ v[i][j][1];
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}