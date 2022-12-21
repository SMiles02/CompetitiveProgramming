#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

int getRand(int l, int r) {
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

struct Hash
{
    // All 1-indexed
    int baseCnt, maxLen, cur = 0;
    vector<vector<int>> bases, inverse;
    vector<vector<vector<int>>> hashVal;
    Hash(int baseCnt, int maxLen) : baseCnt(baseCnt), maxLen(maxLen), bases(baseCnt, vector<int>(maxLen + 1)), inverse(baseCnt, vector<int>(maxLen + 1)) {
        for (int i = 0; i < baseCnt; ++i) {
            bases[i][0] = 1;
            bases[i][1] = getRand(10000, 200000);
            inverse[i][0] = 1;
            inverse[i][1] = binpow(bases[i][1], MOD - 2);
            for (int j = 2; j <= maxLen; ++j) {
                bases[i][j] = mul(bases[i][j - 1], bases[i][1]);
                inverse[i][j] = mul(inverse[i][j - 1], inverse[i][1]);
            }
        }
        hashVal.push_back({{}});
    }
    void addString(string& s) {
        int n = s.size();
        ++cur;
        hashVal.push_back(vector<vector<int>>(baseCnt, vector<int>(n + 1)));
        for (int i = 0; i < baseCnt; ++i)
            for (int j = 0; j < n; ++j)
                hashVal[cur][i][j + 1] = add(hashVal[cur][i][j], mul(bases[i][j], s[j] - 'a' + 1));
    }
    int calcVal(int id, int base, int l, int r) {
        return mul(sub(hashVal[id][base][r], hashVal[id][base][l - 1]), inverse[base][l - 1]);
    }
    bool isEqual(int id1, int l1, int r1, int id2, int l2, int r2) {
        for (int i = 0; i < baseCnt; ++i)
            if (calcVal(id1, i, l1, r1) != calcVal(id2, i, l2, r2))
                return false;
        return true;
    }
};

const int N = 2e5 + 1, S = 450;
int trie[N][26], x[N], node_cnt = 1;

void add_string(string& s) {
    int cur = 0;
    for (auto i : s) {
        if (!trie[cur][i - 'a'])
            trie[cur][i - 'a'] = node_cnt++;
        cur = trie[cur][i - 'a'];
    }
    ++x[cur];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s, t;
    cin >> s;
    int n = s.size(), m, k, cur = 1;
    Hash hash(2, 2e5);
    hash.addString(s);
    vector<int> v(n + 1), w(n + 1);
    cin >> m;
    while (m--) {
        cin >> t;
        k = t.size();
        if (k > S) {
            hash.addString(t);
            ++cur;
            for (int i = 1; i + k - 1 <= n; ++i)
                if (hash.isEqual(1, i, i + k - 1, cur, 1, k)) {
                    ++v[i + k - 1];
                    ++w[i];
                }
        }
        else
            add_string(t);
    }
    for (int i = 0; i < n; ++i) {
        cur = 0;
        for (int j = i; j < n && trie[cur][s[j] - 'a']; ++j) {
            cur = trie[cur][s[j] - 'a'];
            v[j + 1] += x[cur];
            w[i + 1] += x[cur];
        }
    }
    long long ans = 0;
    for (int i = 1; i < n; ++i)
        ans += 1LL * v[i] * w[i + 1];
    cout << ans;
    return 0;
}