#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int sub[N];
double ans[N];
vector<int> e[N];

void dfs(int c) {
    sub[c] = 1;
    for (int i : e[c]) {
        dfs(i);
        sub[c] += sub[i];
    }
}

void solve(int c) {
    for (int i : e[c]) {
        ans[i] = ans[c] + 1 + ((double)sub[c] - sub[i] - 1) / 2;
        solve(i);
    }
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
    ans[1] = 1;
    solve(1);
    for (int i = 1; i <= n; ++i) {
        cout << fixed << setprecision(15) << ans[i] << " ";
    }
    return 0;
}