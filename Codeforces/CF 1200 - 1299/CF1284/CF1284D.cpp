#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int get_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

const int MOD = 1e9 + 7, B = 5;

array<int, B> add(array<int, B> a, array<int, B> b) {
    for (int i = 0; i < B; ++i) {
        a[i] += b[i];
        if (a[i] >= MOD)
            a[i] -= MOD;
    }
    return a;
}

array<int, B> sub(array<int, B> a, array<int, B> b) {
    for (int i = 0; i < B; ++i) {
        a[i] -= b[i];
        if (a[i] < 0)
            a[i] += MOD;
    }
    return a;
}

array<int, B> mul(array<int, B> a, array<int, B> b) {
    for (int i = 0; i < B; ++i)
        a[i] = (1LL * a[i] * b[i]) % MOD;
    return a;
}

array<int, B> solve(set<int>& t, map<int, array<int, B>>& plus, map<int, array<int, B>>& minus) {
    array<int, B> ans{}, cur{};
    for (auto i : t) {
        if (plus.find(i) != plus.end()) {
            ans = add(ans, mul(cur, plus[i]));
            cur = add(cur, plus[i]);
        }
        if (minus.find(i) != minus.end())
            cur = sub(cur, minus[i]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, a, b, c, d;
    cin >> n;
    vector<array<int, B>> bases(n);
    for (int i = 0; i < B; ++i)
        bases[0][i] = get_rand(2, 2);
    map<int, array<int, B>> plus1, minus1, plus2, minus2;
    set<int> t1, t2;
    array<int, B> same_mul1{}, same_mul2{};
    for (int i = 0; i < n; ++i) {
        if (i > 0)
            bases[i] = mul(bases[i - 1], bases[0]);
        cin >> a >> b >> c >> d;
        t1.insert(a);
        t1.insert(b);
        t2.insert(c);
        t2.insert(d);
        same_mul1 = add(same_mul1, mul(plus1[a], bases[i]));
        plus1[a] = add(plus1[a], bases[i]);
        minus1[b] = add(minus1[b], bases[i]);
        same_mul2 = add(same_mul2, mul(plus2[c], bases[i]));
        plus2[c] = add(plus2[c], bases[i]);
        minus2[d] = add(minus2[d], bases[i]);
    }
    if (add(same_mul1, solve(t1, plus1, minus1)) == add(same_mul2, solve(t2, plus2, minus2)))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}