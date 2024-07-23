#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 5e5 + 5;
int cnt;
vector<array<int, 2>> e[N][2];
vector<int> ans;
bitset<N> done;

bool dfs(int c) {
    ans.push_back(c);
    if (cnt == 0 && c == 1) {
        return true;
    }
    for (auto [x, i] : e[c][1]) {
        if (!done[i]) {
            
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    cnt = 0;
    for (int i = 0, x, y, z; i < m; ++i) {
        cin >> x >> y >> z;
        e[x][z].push_back({y, i});
        e[y][z].push_back({x, i});
        done[i] = 0;
        cnt += z;
    }
    if (dfs(1)) {
        cout << "YES\n";
        for (int i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}