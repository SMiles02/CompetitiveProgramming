#include <bits/stdc++.h>
using namespace std;

map<int, int> solve_first_half(vector<int>& v, int target) {
    map<int, int> m;
    int n = v.size();
    vector<long long> dp(1 << n);
    for (int i = 1; i < (1 << n); ++i) {
        dp[i] = dp[i ^ (i & -i)] + v[__lg(i & -i)];
        if (dp[i] <= target)
            ++m[dp[i]];
    }
    return m;
}

long long solve_second_half(vector<int>& v, int target, map<int, int>& m) {
    int n = v.size();
    vector<long long> dp(1 << n);
    long long ans = 0;
    for (int i = 1; i < (1 << n); ++i) {
        dp[i] = dp[i ^ (i & -i)] + v[__lg(i & -i)];
        if (dp[i] < target && m.count(target - dp[i]))
            ans += m[target - dp[i]];
        else if (dp[i] == target)
            ++ans;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, t;
    cin >> n >> t;
    vector<int> v, w;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        if (i & 1)
            v.push_back(k);
        else
            w.push_back(k);
    }
    map<int, int> m = solve_first_half(v, t);
    cout << m[t] + solve_second_half(w, t, m);
    return 0;
}