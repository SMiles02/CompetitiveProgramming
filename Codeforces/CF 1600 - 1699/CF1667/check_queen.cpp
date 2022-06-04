// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, x, y;
    cin >> n;
    vector<vector<bool>> v(n + 1, vector<bool> (n + 1, false));
    cin >> k;
    while (k--) {
        cin >> x >> y;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (i == x || j == y || i - j == x - y)
                    v[i][j] = true;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (!v[i][j]) {
                cout << "oof\n";
                cout << i << " " << j << "\n";
                return 0;
            }
    cout << "issoke\n";
    return 0;
}