#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

struct DSU {
    vector<int> pt, rk;
    DSU(int n) : pt(n * 2 + 1), rk(n * 2 + 1) {
        for (int i = 1; i <= n; ++i)
            pt[i] = i;
        for (int i = n + 1; i <= n * 2; ++i) {
            pt[i] = i;
            rk[i] = 1;
        }
    }
    int find_set(int i) {
        return i == pt[i] ? i : pt[i] = find_set(pt[i]);
    }
    void unite(int i, int j) {
        i = find_set(i);
        j = find_set(j);
        if (i != j) {
            if (rk[i] < rk[j])
                swap(i, j);
            pt[j] = i;
            rk[i] += rk[j];
        }
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
};

const int N = 1001;
int a[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int i = 1; i < n; ++i)
        for (int x = 0; x < 2; ++x)
            for (int y = 0; y < 2; ++y) {
                bool ok = true;
                for (int j = 1; j <= m; ++j)
                    
            }
    return 0;
}