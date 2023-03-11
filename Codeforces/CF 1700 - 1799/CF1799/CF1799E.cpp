#include <bits/stdc++.h>
using namespace std;

const int N = 52;
int n, m;
string s[N];
bitset<N> dn[N];
array<int, 4> a;

bool ok(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int x, int y) {
    a[0] = min(a[0], x);
    a[1] = max(a[1], x);
    a[2] = min(a[2], y);
    a[3] = max(a[3], y);
    dn[x][y] = 1;
    for (int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j)
            if (abs(i) + abs(j) == 1 && ok(x + i, y + j) && s[x + i][y + j] == '#' && !dn[x + i][y + j])
                dfs(x + i, y + j);
}

void fill_in() {
    for (int i = 0; i < n; ++i) {
        int last = -1;
        for (int j = 0; j < m; ++j)
            if (s[i][j] == '#') {
                if (last != -1)
                    for (int k = last + 1; k < j; ++k)
                        s[i][k] = '#';
                last = j;
            }
    }
    for (int j = 0; j < m; ++j) {
        int last = -1;
        for (int i = 0; i < n; ++i)
            if (s[i][j] == '#') {
                if (last != -1)
                    for (int k = last + 1; k < i; ++k)
                        s[k][j] = '#';
                last = i;
            }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < m; ++j)
            dn[i][j] = 0;
    }
    fill_in();
    vector<array<int, 4>> v;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (s[i][j] == '#' && !dn[i][j]) {
                a = {i, i, j, j};
                dfs(i, j);
                v.push_back(a);
            }
    if (v.size() == 2) {
        if (v[0][0] > v[1][0])
            swap(v[0], v[1]);
        int a = v[0][1], b, c = v[1][0], d;
        if (v[0][2] < v[1][2]) {
            b = v[0][3];
            d = v[1][2];
        }
        else {
            b = v[0][2];
            d = v[1][3];
        }
        s[a][b] = '#';
        while (a != c || b != d) {
            if (a < c)
                ++a;
            else if (a > c)
                --a;
            else if (b < d)
                ++b;
            else
                --b;
            s[a][b] = '#';
        }
    }
    fill_in();
    for (int i = 0; i < n; ++i)
        cout << s[i] << "\n";
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