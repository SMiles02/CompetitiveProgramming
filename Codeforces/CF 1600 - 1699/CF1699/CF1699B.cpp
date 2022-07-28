#include <bits/stdc++.h>
using namespace std;

const int N = 50;
int a[N][N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    a[0][0] = 1;
    a[0][1] = 0;
    a[0][2] = 0;
    a[0][3] = 1;
    for (int j = 4; j < N; ++j)
        a[0][j] = a[0][j - 4];
    for (int i = 1; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            if (i % 4 == 0 || i % 4 == 3)
                a[i][j] = a[0][j];
            else
                a[i][j] = 1 - a[0][j];
        }
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}