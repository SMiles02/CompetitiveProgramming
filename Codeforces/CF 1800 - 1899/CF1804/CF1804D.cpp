#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, mn = 0, mx = 0;
    cin >> n >> m;
    while (n--) {
        int cnt = 0, x;
        string s;
        cin >> s;
        for (auto i : s)
            cnt += i == '1';
        x = 0;
        for (int i = 1; i < m; ++i) {
            if (s[i] == '1' && s[i - 1] == s[i]) {
                ++x;
                ++i;
            }
        }
        mn += cnt - min(x, m / 4);
        x = 0;
        for (int i = 1; i < m; ++i) {
            if (!(s[i] == '1' && s[i - 1] == s[i])) {
                ++x;
                ++i;
            }
        }
        mx += cnt - max(m / 4 - x, 0);
    }
    cout << mn << " " << mx << "\n";
    return 0;
}