#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
int cmp_size;
bool all_two;
vector<int> e[N];
bitset<N> d;

void dfs(int c) {
    d[c] = 1;
    ++cmp_size;
    all_two &= e[c].size() == 2;
    for (int i : e[c])
        if (!d[i])
            dfs(i);
}

void solve() {
    int n, k, closed = 0, open = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
        d[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        e[i].push_back(k);
        e[k].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        if (!d[i]) {
            cmp_size = 0;
            all_two = true;
            dfs(i);
            if (cmp_size > 2 && all_two)
                ++closed;
            else
                ++open;
        }
    cout << closed + min(open, 1) << " " << closed + open << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}