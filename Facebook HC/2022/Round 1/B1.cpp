#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

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

int sub(int a, int b) { return add(a,MOD-b); }

int solve_dimension(vector<array<int, 2>> &v) {
    int ans = 0, cnt, s1, s2;
    sort(v.begin(), v.end());
    cnt = 0;
    s1 = 0;
    s2 = 0;
    for (auto i : v) {
        if (i[1] == 0) {
            ++cnt;
            s1 = add(s1, i[0]);
            s2 = add(s2, mul(i[0], i[0]));
        }
        else {
            ans = add(ans, mul(cnt, mul(i[0], i[0])));
            ans = sub(ans, mul(2, mul(i[0], s1)));
            ans = add(ans, s2);
        }
    }
    sort(v.rbegin(), v.rend());
    cnt = 0;
    s1 = 0;
    s2 = 0;
    for (auto i : v) {
        if (i[1] == 0) {
            ++cnt;
            s1 = add(s1, i[0]);
            s2 = add(s2, mul(i[0], i[0]));
        }
        else {
            ans = add(ans, mul(cnt, mul(i[0], i[0])));
            ans = sub(ans, mul(2, mul(i[0], s1)));
            ans = add(ans, s2);
        }
    }
    return ans;
}

void solve() {
    int n, q;
    cin >> n;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i][0] >> a[i][1];
    cin >> q;
    vector<array<int, 2>> b(q);
    for (int i = 0; i < q; ++i)
        cin >> b[i][0] >> b[i][1];
    vector<array<int, 2>> v(n + q), w(n + q);
    for (int i = 0; i < n; ++i) {
        v[i] = {a[i][0], 0};
        w[i] = {a[i][1], 0};
    }
    for (int i = 0; i < q; ++i) {
        v[n + i] = {b[i][0], 1};
        w[n + i] = {b[i][1], 1};
    }
    cout << add(solve_dimension(v), solve_dimension(w)) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}