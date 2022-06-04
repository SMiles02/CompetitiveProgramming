// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n, k;
vector<array<int, 2>> ans;

bool trySolve(int dn, vector<vector<int>>& v, int x, int y) {
    if (dn >= k) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (v[i][j] == 0)
                    return false;
        return true;
    }
    if (y == n) {
        y = 0;
        ++x;
    }
    while (x < n) {
        if (v[x][y] == 0) {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (i == x || j == y || i - j == x - y)
                        ++v[i][j];
            ans.push_back({x, y});
            if (trySolve(dn + 1, v, x, y + 1))
                return true;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (i == x || j == y || i - j == x - y)
                        --v[i][j];
            ans.pop_back();
        }
        ++y;
        if (y == n) {
            y = 0;
            ++x;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(n));
    if (trySolve(0, v, 0, 0)) {
        cout << "Found answer for board size " << n << " with " << k << " half-queens:\n";
        for (auto i : ans)
            cout << i[0] + 1 << " " << i[1] + 1 << "\n";
    }
    else
        cout << "No answer.";
    return 0;
}