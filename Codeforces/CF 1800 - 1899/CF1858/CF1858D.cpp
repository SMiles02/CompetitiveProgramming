#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = "?" + s;
    vector<int> ans(n + 2, -1e9);
    vector<vector<array<int, 6>>> v(n + 2, vector<array<int, 6>>(n + 2));
    // l0, l1, i0, i1, r0, r1
    for (int l = 1; l <= n; ++l) {
        bool same = true;
        v[l][l][0] = v[l][l][2] = s[l] == '0';
        v[l][l][1] = v[l][l][3] = s[l] == '1';
        int cur = 1;
        for (int r = l + 1; r <= n; ++r) {
            v[l][r] = v[l][r - 1];
            same &= s[r] == s[r - 1];
            if (s[r] == s[r - 1]) {
                ++cur;
            }
            else {
                cur = 1;
            }
            if (same) {
                v[l][r][s[r] - '0'] = cur;
            }
            v[l][r][(int)(s[r] - '0') + 2] = max(v[l][r][(int)(s[r] - '0') + 2], cur);
        }
    }
    for (int r = n; r > 0; --r) {
        bool same = true;
        v[r][r][(int)(s[r] - '0') + 4] = 1;
        for (int l = r - 1; l > 0; --l) {
            same &= s[l] == s[l + 1];
            v[l][r][4] = v[l + 1][r][4];
            v[l][r][5] = v[l + 1][r][5];
            if (same) {
                ++v[l][r][(int)(s[l] - '0') + 4];
            }
        }
    }
    ans[v[1][n][2]] = v[1][n][3];
    for (int i = 1; i + k - 1 <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int x = max({v[1][i - 1][2], v[1][i - 1][4] + j - i + 1, v[i + k][n][2]});
            int y = max({v[1][i - 1][3], k - j + i - 1 + v[i + k][n][1], v[i + k][n][3]});
            // cout << i << " " << j << ": " << x << " " << y << "\n";
            ans[x] = max(ans[x], y);
            x = max({v[1][i - 1][2], k - j + i - 1 + v[i + k][n][0], v[i + k][n][2]});
            y = max({v[1][i - 1][3], v[1][i - 1][5] + j - i + 1, v[i + k][n][3]});
            ans[x] = max(ans[x], y);
        }
        int x, y;
        x = max({v[1][i - 1][2], v[1][i - 1][4] + k + v[i + k][n][0], v[i + k][n][2]});
        y = max({v[1][i - 1][3], v[i + k][n][3]});
        ans[x] = max(ans[x], y);
        x = max({v[1][i - 1][2], v[i + k][n][2]});
        y = max({v[1][i - 1][3], v[1][i - 1][5] + k + v[i + k][n][1], v[i + k][n][3]});        
        ans[x] = max(ans[x], y);
    }
    for (int i = 1; i <= n; ++i) {
        int cur_ans = 0;
        for (int j = 0; j <= n; ++j) {
            cur_ans = max(cur_ans, i * j + ans[j]);
        }
        cout << cur_ans << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}