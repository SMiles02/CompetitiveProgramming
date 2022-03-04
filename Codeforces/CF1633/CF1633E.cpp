#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;

const int N = 51;
int pt[N], rk[N];

bool cmp(array<int, 3>& a, array<int, 3>& b) {
    return a[0] < b[0];
}

int find_set(int v) {
    if (v == pt[v]) return v;
    return pt[v] = find_set(pt[v]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, p, k, a, b, c, q, x, y;
    long long ans = 0, cur;
    cin >> n >> m;
    array<int, 3> f[m], e[m];
    for (int i = 0; i < m; ++i)
        cin >> f[i][1] >> f[i][2] >> f[i][0];
    cin >> p >> k >> a >> b >> c;
    for (int _ = 0; _ < p; ++_) {
        cin >> q;
        cur = 0;
        for (int i = 0; i < m; ++i)
            e[i] = {abs(f[i][0] - q), f[i][1], f[i][2]};
        sort(e, e + m, cmp);
        for (int i = 1; i <= n; ++i) {
            pt[i] = i;
            rk[i] = 1;
        }
        for (int i = 0; i < m; ++i) {
            x = find_set(e[i][1]);
            y = find_set(e[i][2]);
            if (x != y) {
                if (rk[x] < rk[y])
                    swap(x, y);
                pt[y] = pt[x];
                rk[x] += rk[y];
                cur += e[i][0];
            }
        }
        ans ^= cur;
    }
    for (int _ = p; _ < k; ++_) {
        q = (1LL * q * a + b) % c;
        cur = 0;
        for (int i = 0; i < m; ++i)
            e[i] = {abs(f[i][0] - q), f[i][1], f[i][2]};
        sort(e, e + m, cmp);
        for (int i = 1; i <= n; ++i) {
            pt[i] = i;
            rk[i] = 1;
        }
        for (int i = 0; i < m; ++i) {
            x = find_set(e[i][1]);
            y = find_set(e[i][2]);
            if (x != y) {
                if (rk[x] < rk[y])
                    swap(x, y);
                pt[y] = pt[x];
                rk[x] += rk[y];
                cur += e[i][0];
            }
        }
        ans ^= cur;
    }
    cout << ans;
    return 0;
}