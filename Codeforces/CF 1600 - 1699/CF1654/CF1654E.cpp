// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

int main() {
    double start = clock();
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, ans = 1, cur, x, y;
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    shuffle(v.begin(), v.end(), rng);
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int x = 0; x < n; ++x)
        for (int y = x + 1; y < n && (clock()-start)/double(CLOCKS_PER_SEC)<4.9; ++y) {
            cur = 0;
            for (int i = 0; i < n; ++i)
                cur += (1LL * (v[x] - i) * (a[v[y]] - a[i]) == 1LL * (v[y] - i) * (a[v[x]] - a[i]));
            ans = max(ans, cur);
        }
    cout << n - ans;
    return 0;
}