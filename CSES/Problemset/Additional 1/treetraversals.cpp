#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 2;
int l[N], r[N], pre[N], in[N], in_pos[N];
 
void solve(int lp, int rp, int li, int ri) {
    if (lp == rp)
        return;
    if (in_pos[pre[lp]] > in_pos[pre[lp + 1]]) {
        l[pre[lp]] = pre[lp + 1];
        if (in_pos[pre[lp]] == ri)
            solve(lp + 1, rp, li, ri - 1);
        else
            solve(lp + 1, lp + in_pos[pre[lp]] - li, li, in_pos[pre[lp]] - 1);
    }
    if (in_pos[pre[lp]] != ri) {
        r[pre[lp]] = pre[lp + in_pos[pre[lp]] - li + 1];
        if (in_pos[pre[lp]] > in_pos[pre[lp + 1]])
            solve(lp + in_pos[pre[lp]] - li + 1, rp, in_pos[pre[lp]] + 1, ri);
        else
            solve(lp + 1, rp, in_pos[pre[lp]] + 1, ri);
    }
}
 
void dfs(int c) {
    if (l[c])
        dfs(l[c]);
    if (r[c])
        dfs(r[c]);
    cout << c << " ";
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> pre[i];
    for (int i = 1; i <= n; ++i) {
        cin >> in[i];
        in_pos[in[i]] = i;
    }
    solve(1, n, 1, n);
    dfs(pre[1]);
    return 0;
}