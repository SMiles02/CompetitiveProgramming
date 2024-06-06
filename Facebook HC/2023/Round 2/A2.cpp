#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 3003;
int n, m, ans[N][N], dfssz, bx, by;
bool nub;
string s[N];
bitset<N> done[N];
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

bool ok(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int x, int y) {
    done[x][y] = 1;
    ++dfssz;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (ok(nx, ny)) {
            if (s[nx][ny] == 'W' && !done[nx][ny]) {
                dfs(nx, ny);
            }
            else if (s[nx][ny] == '.') {
                if (bx == -1) {
                    bx = nx;
                    by = ny;
                }
                else if (bx != nx || by != ny) {
                    nub = true;
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < m; ++j) {
            done[i][j] = 0;
            ans[i][j] = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'W' && !done[i][j]) {
                nub = false;
                dfssz = 0;
                bx = -1;
                by = -1;
                dfs(i, j);
                if (!nub && bx != -1) {
                    ans[bx][by] += dfssz;
                }
            }
        }
    }
    int final_ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            final_ans = max(final_ans, ans[i][j]);
        }
    }
    cout << final_ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}