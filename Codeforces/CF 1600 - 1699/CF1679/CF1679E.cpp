#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

const int N = 17, M = 501;
int n, dp[1 << N][M];
string s;

void calc(int l, int r) {
    int cur = 0, mask = 0;
    while (0 <= l && r < n) {
        if (s[l] == '?' && s[r] == '?')
            ++cur;
        else if (s[l] == '?')
            mask |= (1 << (s[r] - 'a'));
        else if (s[r] == '?')
            mask |= (1 << (s[l] - 'a'));
        else if (s[l] != s[r])
            return;
        ++dp[mask][cur];
        --l;
        ++r;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        calc(i, i);
        calc(i, i + 1);
    }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < (1 << N); ++j)
            if ((1 << i) & j)
                for (int k = 0; k < M; ++k)
                    dp[j][k] = add(dp[j][k], dp[j ^ (1 << i)][k]);
    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;
        int cur = 0, ans = 0, x = 1;
        for (auto i : t)
            cur ^= (1 << (i - 'a'));
        for (int k = 0; k < M; ++k) {
            ans = add(ans, mul(x, dp[cur][k]));
            x = mul(x, t.size());
        }
        cout << ans << "\n";
    }
    return 0;
}