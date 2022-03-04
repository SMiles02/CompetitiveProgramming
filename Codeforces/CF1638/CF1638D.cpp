#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1001;
int n, m, a[N][N];
bitset<N> done[N];
vector<array<int, 3>> ans;

bool ok(int x, int y) {
    return (1 <= min(x, y) && x + 1 <= n && y + 1 <= m);
}

void check(int x, int y) {
    if (done[x][y])
        return;
    set<int> s;
    s.insert(a[x][y]);
    s.insert(a[x][y + 1]);
    s.insert(a[x + 1][y]);
    s.insert(a[x + 1][y + 1]);
    if (s.size() > 2 || (s.size() == 2 && *s.begin() != 0) || (s.size() == 1 && *s.begin() == 0))
        return;
    ans.push_back({x, y, *--s.end()});
    a[x][y] = a[x][y + 1] = a[x + 1][y] = a[x + 1][y + 1] = 0;
    done[x][y] = 1;
    for (int i = x - 1; i <= x + 1; ++i)
        for (int j = y - 1; j <= y + 1; ++j)
            if (ok(i, j))
                check(i, j);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int i = n - 1; i > 0; --i)
        for (int j = m - 1; j > 0; --j)
            check(i, j);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] != 0) {
                cout << -1;
                return 0;
            }
    cout << ans.size() << "\n";
    while (!ans.empty()) {
        for (int i : ans.back())
            cout << i << " ";
        cout << "\n";
        ans.pop_back();
    }
    return 0;
}