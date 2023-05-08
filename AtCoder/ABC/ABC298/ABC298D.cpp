#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 998244353, N = 6e5 + 3;

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b) { return (1LL * a * b) % MOD; }

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int dv(int a, int b) { return mul(a, binpow(b, MOD - 2)); }

int sub(int a, int b) { return add(a, MOD - b); }

int p10[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    p10[0] = 1;
    for (int i = 1; i < N; ++i)
        p10[i] = mul(p10[i - 1], 10);
    int n, ans = 1, len = 1;
    queue<int> q;
    q.push(1);
    cin >> n;
    while (n--) {
        int t, x;
        cin >> t;
        if (t == 1) {
            cin >> x;
            ans = mul(ans, 10);
            ans = add(ans, x);
            q.push(x);
            ++len;
        }
        else if (t == 2) {
            ans = sub(ans, mul(q.front(), p10[len - 1]));
            q.pop();
            --len;
        }
        else
            cout << ans << "\n";
    }
    return 0;
}