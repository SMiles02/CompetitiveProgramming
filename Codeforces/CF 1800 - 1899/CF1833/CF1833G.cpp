#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5 + 1;
vector<array<int, 2>> e[N];
vector<int> ans;
bitset<3> dp[N];
bitset<N> dont_go;

void dfs(int c, int p = 0) {
    int chd = 0, last_child;
    vector<int> cnt(3), undone;
    dp[c][0] = dp[c][1] = dp[c][2] = 0;
    for (auto i : e[c])
        if (i[0] != p) {
            ++chd;
            dfs(i[0], c);
            for (int j = 0; j < 3; ++j)
                cnt[j] += dp[i[0]][j];
            last_child = i[0];
            if (!dp[i[0]][2])
                undone.push_back(i[0]);
        }
    if (chd == 0)
        dp[c][0] = 1;
    else if (chd == 1)
        for (int j = 0; j < 3; ++j)
            dp[c][(j + 1) % 3] = dp[last_child][j];
    else {
        if (cnt[2] >= chd - 2) {
            int both = 0, one = 0;
            for (auto i : e[c])
                if (i[0] != p) {
                    if (dp[i[0]][0] && dp[i[0]][2])
                        ++both;
                    else if (dp[i[0]][0])
                        ++one;
                }
            // one is in [0, 2]
            // need 2 - one from both
            // cout << c << " " << both << " " << one << "!\n";
            if (cnt[2] - 2 + one >= chd - 2 && both >= 2 - one)
                dp[c][2] = 1;
        }
        if (cnt[2] == chd)
            for (int j = 0; j < 3; ++j)
                dp[c][(j + 1) % 3] = dp[c][(j + 1) % 3] | (cnt[j] > 0);
        else if (cnt[2] == chd - 1)
            for (int j = 0; j < 3; ++j)
                dp[c][(j + 1) % 3] = dp[c][(j + 1) % 3] | dp[undone[0]][j];
    }
    // cerr << c << ": ";
    // for (int j = 0; j < 3; ++j)
    //     cerr << dp[c][j] << " ";
    // cerr << "\n";
}

void find_edges(int c, int x, int p = 0) {
    // cout << "solving " << c << " for " << x << "\n";
    int chd = 0, last_child;
    vector<int> cnt(3);
    vector<array<int, 2>> undone;
    dp[c][0] = dp[c][1] = dp[c][2] = 0;
    for (auto i : e[c])
        if (i[0] != p) {
            ++chd;
            for (int j = 0; j < 3; ++j)
                cnt[j] += dp[i[0]][j];
            last_child = i[0];
            if (!dp[i[0]][2])
                undone.push_back(i);
        }
    if (chd == 0)
        return;
    else if (chd == 1) {
        for (auto i : e[c])
            if (i[0] != p) {
                if (x == 0)
                    ans.push_back(i[1]);
                find_edges(i[0], (x + 2) % 3, c);
                return;
            }
        assert(false);
    }
    else {
        if (cnt[2] >= chd - 2 && x == 2) {
            vector<array<int, 2>> both, one;
            for (auto i : e[c])
                if (i[0] != p) {
                    if (dp[i[0]][0] && dp[i[0]][2])
                        both.push_back(i);
                    else if (dp[i[0]][0])
                        one.push_back(i);
                }
            if (cnt[2] - 2 + one.size() >= chd - 2 && both.size() >= 2 - one.size()) {
                int dn = 0;
                for (auto i : both) {
                    find_edges(i[0], 0, c);
                    ++dn;
                    dont_go[i[0]] = 1;
                }
                for (auto i : e[c])
                    if (i[0] != p && !dont_go[i[0]]) {
                        if (dn < 2 && dp[i[0]][0])
                            find_edges(i[0], 0, c);
                        else {
                            ans.push_back(i[1]);
                            find_edges(i[0], 2, c);
                        }
                    }
                return;
            }
        }
        if (cnt[2] == chd) {
            bool done = false;
            for (auto i : e[c])
                if (i[0] != p) {
                    if (!done && dp[i[0]][(x + 2) % 3]) {
                        done = true;
                        if (x == 0)
                            ans.push_back(i[1]);
                        find_edges(i[0], (x + 2) % 3, c);
                    }
                    else {
                        ans.push_back(i[1]);
                        find_edges(i[0], 2, c);
                    }
                }
            if (!done)
                assert(false);
            return;
        }
        else if (cnt[2] == chd - 1) {
            for (auto i : e[c])
                if (i[0] != p && i[0] != undone[0][0]) {
                    ans.push_back(i[1]);
                    find_edges(i[0], 2, c);
                }
            if (x == 0)
                ans.push_back(undone[0][1]);
            find_edges(undone[0][0], (x + 2) % 3, c);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
        dont_go[i] = 0;
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        e[x].push_back({y, i});
        e[y].push_back({x, i});
    }
    dfs(1);
    if (!dp[1][2]) {
        cout << "-1\n";
        return;
    }
    ans.clear();
    find_edges(1, 2);
    cout << ans.size() << "\n";
    for (int i : ans)
        cout << i << " ";
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