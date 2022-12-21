#include <bits/stdc++.h>
using namespace std;

const int N = 402;
int h[N][N][N], p[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; ++i)
        cin >> s;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1][j - 1] == 'm')
                p[i][j] = 1;
            else if (s[i - 1][j - 1] == '#')
                p[i][j] = 2;
            p[i][j] += p[i][j - 1];
        }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                h[i][j][k] = 2;
    for (int i = 1; i <= m; ++i)
        for (int j = i + 2; i <= m; ++j)
            for (int k = 1; k <= n; ++k)
                h[i][j][k] = h[i][j][k - 1] + (p[k][j - 1] - )
    return 0;
}