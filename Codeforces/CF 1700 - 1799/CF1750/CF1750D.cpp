#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 998244353, N = 2e5+1;
int f[N];

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

int sub(int a, int b) { return add(a,MOD-b); }

int C(int n, int k) { return dv(f[n],mul(f[k],f[n-k])); }

void calc_factorials() {
    f[0]=1;
    for (int i=1;i<N;++i) f[i]=mul(f[i-1],i);
}

const int L = 10;
int mx;
vector<int> layer[L];

void build(int cur, int pd, int i, bool took) {
    if (took && cur > 1)
        layer[cur].push_back(pd);
    if (i == mx)
        return;
    build(cur, pd, i + 1, 0);
    build(cur + 1, pd * layer[1][i], i + 1, 1);
}

void get_prime(int k) {
    for (int i = 1; i < L; ++i)
        layer[i].clear();
    if (k % 2 == 0) {
        layer[1].push_back(2);
        while (k % 2 == 0)
            k /= 2;
    }
    for (int i = 3; i * i <= k; i += 2)
        if (k % i == 0) {
            layer[1].push_back(i);
            while (k % i == 0)
                k /= i;
        }
    if (k > 1)
        layer[1].push_back(k);
    mx = layer[1].size();
    build(0, 1, 0, 0);
    // for (int i = 1; i < L; ++i) {
    //     cout << i << ": ";
    //     for (int j : layer[i])
    //         cout << j << " ";
    //     cout << "\n";
    // }
}

void solve() {
    int n, m, ans = 1, cur;
    cin >> n >> m;
    int a[n], b[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    b[0] = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] % a[i] != 0) {
            cout << "0\n";
            return;
        }
        get_prime(a[i - 1] / a[i]);
        cur = (m / a[i]) % MOD;
        for (int j = 1; j < L; ++j) {
            if (j & 1) {
                for (int k : layer[j])
                    cur = sub(cur, m / (a[i] * k));
            }
            else {
                for (int k : layer[j])
                    cur = add(cur, m / (a[i] * k));
            }
        }
        ans = mul(ans, cur);
        // cerr << ans << " ";
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}