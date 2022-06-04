#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353, N = 2e5 + 1;
int min_prime[N], f[N], cur[N], x, y, ans;
vector<int> primes;
vector<array<int, 3>> e[N];

int add(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}

int mul(int a, int b) { return (1LL*a*b)%MOD; }

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}

int dv(int a, int b) { return mul(a,binpow(b,MOD-2)); }

void dfs(int c, int p) {
    for (auto i : e[c])
        if (i[0] != p) {
            x = i[1];
            y = i[2];
            while (y > 1) {
                ++cur[min_prime[y]];
                y /= min_prime[y];
            }
            while (x > 1) {
                --cur[min_prime[x]];
                f[min_prime[x]] = max(f[min_prime[x]], - cur[min_prime[x]]);
                x /= min_prime[x];
            }
            dfs(i[0], c);
        }
    for (auto i : e[c])
        if (i[0] == p) {
            x = i[1];
            y = i[2];
            while (y > 1) {
                ++cur[min_prime[y]];
                y /= min_prime[y];
            }
            while (x > 1) {
                --cur[min_prime[x]];
                x /= min_prime[x];
            }
        }
}

void dfsAns(int c, int p, int curScore) {
    ans = add(ans, curScore);
    for (auto i : e[c])
        if (i[0] != p)
            dfsAns(i[0], c, mul(dv(curScore, i[1]), i[2]));
}

void solve() {
    int n, a, b, c, d, g, tmp = 1;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        e[i].clear();
    for (int i = 1; i < n; ++i) {
        cin >> a >> b >> c >> d;
        e[a].push_back({b, c, d});
        e[b].push_back({a, d, c});
    }
    for (int i : primes) {
        f[i] = 0;
        cur[i] = 0;
    }
    dfs(1, 0);
    for (int i : primes)
        if (f[i] > 0)
            tmp = mul(tmp, binpow(i, f[i]));
    ans = 0;
    dfsAns(1, 0, tmp);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 2; i < N; ++i)
        if (min_prime[i] == 0) {
            primes.push_back(i);
            for (int j = i; j < N; j += i)
                if (min_prime[j] == 0)
                    min_prime[j] = i;
        }
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}