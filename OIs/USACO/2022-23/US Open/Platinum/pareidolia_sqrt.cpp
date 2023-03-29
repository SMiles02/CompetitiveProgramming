// partial sol, gets 12/20 testcases

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1, S = 450, M = 6;
int n, range[S][2], nex[M], pre[M];
array<int, M * 3 + 1> dp[S];
string target = "bessie", s;

void calc_dp(int i) {
    for (int j = 0; j <= M * 3; ++j)
        dp[i][j] = 0;
    for (int j = 0; j < M; ++j)
        dp[i][j + M] = j;
    for (int j = range[i][0]; j < range[i][1]; ++j) {
        array<int, M> tmp_dp{};
        ++dp[i][M - 1];
        for (int k = 0; k < M; ++k) {
            if (s[j] == target[k]) {
                tmp_dp[k] += dp[i][pre[k]];
                if (k == M - 1)
                    dp[i][M * 3] += (n - j) * dp[i][pre[k]];
            }
            else
                tmp_dp[pre[k]] += dp[i][pre[k]];
        }
        for (int k = 0; k < M; ++k) {
            if (s[j] == target[nex[dp[i][k + M]]]) {
                dp[i][k + M] = nex[dp[i][k + M]];
                if (dp[i][k + M] == M - 1)
                    dp[i][k + M * 2] += n - j;
            }
            else
                dp[i][k + M] = dp[i][k + M];
        }
        for (int k = 0; k < M; ++k)
            dp[i][k] = tmp_dp[k];
    }
}

long long calc_ans() {
    long long ans = 0;
    array<int, M> ans_dp{};
    for (int i = 0; i * S < n; ++i) {
        ans += dp[i][M * 3];
        array<int, M> go_to{};
        for (int j = 0; j < M; ++j) {
            ans += 1LL * ans_dp[j] * dp[i][j + M * 2];
            go_to[dp[i][j + M]] += ans_dp[j];
        }
        for (int j = 0; j < M; ++j)
            ans_dp[j] = go_to[j] + dp[i][j];
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    n = s.size();
    for (int i = 0; i + 1 < M; ++i) {
        nex[i] = i + 1;
        pre[i + 1] = i;
    }
    nex[M - 1] = 0;
    pre[0] = M - 1;
    for (int i = 0; i * S < n; ++i) {
        range[i][0] = i * S;
        range[i][1] = min(n, (i + 1) * S);
        calc_dp(i);
    }
    cout << calc_ans() << "\n";
    int q;
    cin >> q;
    while (q--) {
        int i;
        char c;
        cin >> i >> c;
        --i;
        s[i] = c;
        calc_dp(i / S);
        cout << calc_ans() << "\n";
    }
    return 0;
}