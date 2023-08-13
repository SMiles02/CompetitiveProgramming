#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6 + 1;
int sub[N];
ll ans;
vector<int> e[N];

void dfs(int c) {
    bitset<N> dp;
    dp[0] = 1;
    for (int i : e[c]) {
        dfs(i);
        dp |= dp << sub[i];
        sub[c] += sub[i];
    }
    ll cur = 0;
    for (int i = 1; i < sub[c]; ++i) {
        if (dp[i]) {
            cur = max(cur, 1LL * i * (sub[c] - i));
        }
    }
    ans += cur;
    ++sub[c];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        e[p].push_back(i);
    }
    dfs(1);
    cout << ans;
    return 0;
}