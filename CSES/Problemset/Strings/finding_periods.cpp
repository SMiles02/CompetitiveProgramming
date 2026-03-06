#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

int get_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

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

int sub(int a, int b) { return add(a, MOD - b); }

struct string_hash {
    // All 1-indexed
    int base_cnt, max_len, cur = 0;
    vector<vector<int>> bases, inverse;
    vector<vector<vector<int>>> hash_val;
    string_hash(int base_cnt, int max_len) : base_cnt(base_cnt), max_len(max_len), bases(base_cnt, vector<int>(max_len + 1)), inverse(base_cnt, vector<int>(max_len + 1)) {
        for (int i = 0; i < base_cnt; ++i) {
            bases[i][0] = 1;
            bases[i][1] = get_rand(10000, 200000);
            inverse[i][0] = 1;
            inverse[i][1] = binpow(bases[i][1], MOD - 2);
            for (int j = 2; j <= max_len; ++j) {
                bases[i][j] = mul(bases[i][j - 1], bases[i][1]);
                inverse[i][j] = mul(inverse[i][j - 1], inverse[i][1]);
            }
        }
        hash_val.push_back({{}});
    }
    int char_value(char c) {
        return c - 'a' + 1;
    }
    void add_string(string& s) {
        int n = s.size();
        ++cur;
        hash_val.push_back(vector<vector<int>>(base_cnt, vector<int>(n + 1)));
        for (int i = 0; i < base_cnt; ++i)
            for (int j = 0; j < n; ++j)
                hash_val[cur][i][j + 1] = add(hash_val[cur][i][j], mul(bases[i][j], s[j]));
    }
    int calc_val(int id, int base, int l, int r) {
        return mul(sub(hash_val[id][base][r], hash_val[id][base][l - 1]), inverse[base][l - 1]);
    }
    bool is_equal(int id1, int l1, int r1, int id2, int l2, int r2) {
        for (int i = 0; i < base_cnt; ++i)
            if (calc_val(id1, i, l1, r1) != calc_val(id2, i, l2, r2))
                return false;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    string_hash hash(2, n);
    hash.add_string(s);
    for (int i = 1; i <= n; ++i) {
        bool ok = true;
        int cur = i;
        while (cur != n && ok) {
            if (cur * 2 <= i) {
                ok &= hash.is_equal(1, 1, cur, 1, cur + 1, cur * 2);
                cur *= 2;
            }
            else {
                ok &= hash.is_equal(1, 1, n - cur, 1, cur + 1, n);
                cur = n;
            }
        }
        if (ok) cout << i << " ";
    }
    return 0;
}