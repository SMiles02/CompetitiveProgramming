#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9+7;

int getRand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    Hash hash(3, 1e6);
    int ans = 0, n, m;
    string s, t;
    cin >> s;
    cin >> t;
    n = s.size();
    m = t.size();
    hash.addString(s);
    hash.addString(t);
    for (int i = m; i <= n; ++i)
        ans += hash.isEqual(1, i - m + 1, i, 2, 1, m);
    cout << ans;
    return 0;
}