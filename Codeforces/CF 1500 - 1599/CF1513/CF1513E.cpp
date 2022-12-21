#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, N = 1e5 + 1;
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

int calc(vector<array<int, 2>> v) {
    int ans = 1, cur = 0;
    for (auto i : v) {
        cur += i[1];
        ans = mul(ans, C(cur, i[1]));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    calc_factorials();
    int n;
    cin >> n;
    long long s = 0;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
    }
    sort(a, a + n);
    if (s % n) {
        cout << "0\n";
        return 0;
    }
    int cnt = 0, ans = 1;
    vector<array<int, 2>> v, w;
    for (int i = 0; i < n; ++i) {
        if (a[i] < s / n) {
            if (v.empty() || v.back()[0] != a[i])
                v.push_back({a[i], 1});
            else
                ++v.back()[1];
        }
        else if (a[i] > s / n) {
            if (w.empty() || w.back()[0] != a[i])
                w.push_back({a[i], 1});
            else
                ++w.back()[1];
        }
        else
            ++cnt;
    }
    if (v.empty() || w.empty() || (v.size() == 1 && v[0][1] == 1) || (w.size() == 1 && w[0][1] == 1)) {
        for (auto i : w)
            v.push_back(i);
        v.push_back({0, cnt});
        cout << calc(v);
        return 0;
    }
    cout << mul(mul(C(n, cnt), 2), mul(calc(v), calc(w)));
    return 0;
}