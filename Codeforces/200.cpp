#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int n, m;
string s[N];
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

bool ok(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < m);
}

void dfs(int x, int y, char c, char d) {
    s[x][y] = d;
    for (int i = 0; i < 4; ++i)
        if (ok(x + dx, y + dy) && s[x + dx][y + dy] == c)
            dfs(x + dx, y + dy, c, d);
}
];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> s[i    dfs(0, 0, s[0][0], 'z');
    return 0;
}