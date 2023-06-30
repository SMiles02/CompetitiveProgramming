#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

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


const int N = 2e5 + 1;
int n, sum, subt[N];
vector<int> e[N];

void dfs(int c, int p = 0) {
    subt[c] = 1;
    for (int i : e[c])
        if (i != p) {
            dfs(i, c);
            sum = add(sum, mul(subt[c], subt[i]));
            subt[c] += subt[i];
        }
    sum = add(sum, mul(subt[c], n - subt[c]));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k;
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    if (k == 1 || k == 3) {
        cout << 1;
        return 0;
    }
    dfs(1);
    cout << dv(sum, dv(mul(n, n - 1), 2));
    return 0;
}