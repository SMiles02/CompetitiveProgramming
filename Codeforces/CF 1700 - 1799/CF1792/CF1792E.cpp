#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<array<int, 2>> primes;
vector<int> v;
vector<ll> nums;
vector<vector<int>> factorisation;

void gen_factors(int i, ll x) {
    if (i == primes.size()) {
        factorisation.push_back(v);
        nums.push_back(x);
        return;
    }
    v[i] = 0;
    for (int j = 0; j <= primes[i][1]; ++j) {
        gen_factors(i + 1, x);
        ++v[i];
        x *= primes[i][0];
    }
}

void solve() {
    primes.clear();
    nums.clear();
    factorisation.clear();
    int n, x, y, ans1 = 0, ans2 = 0;
    cin >> n >> x >> y;
    ll m = 1LL * x * y;
    if (x == 1 && y == 1) {
        cout << "1 1\n";
        return;
    }
    for (int i = 2; i * i <= max(x, y); ++i)
        if (x % i == 0 || y % i == 0) {
            primes.push_back({i, 0});
            while (x % i == 0) {
                ++primes.back()[1];
                x /= i;
            }
            while (y % i == 0) {
                ++primes.back()[1];
                y /= i;
            }
        }
    if (x > y)
        swap(x, y);
    if (x == y && x > 1) {
        primes.push_back({x, 2});
        x = y = 1;
    }
    if (x > 1)
        primes.push_back({x, 1});
    if (y > 1)
        primes.push_back({y, 1});
    v.resize(primes.size());
    gen_factors(0, 1);
    vector<array<ll, 2>> factors(factorisation.size());
    vector<int> dp(factors.size());
    for (int i = 0; i < factorisation.size(); ++i)
        factors[i] = {nums[i], i};
    sort(factors.begin(), factors.end());
    for (auto i : factors) {
        dp[i[1]] = 1;
        if (i[0] <= n)
            dp[i[1]] = i[0];
        int cur = factors.size();
        for (int j = 0; j < primes.size(); ++j) {
            cur /= primes[j][1] + 1;
            if (factorisation[i[1]][j] > 0)
                dp[i[1]] = max(dp[i[1]], dp[i[1] - cur]);
        }
        if (i[0] / dp[i[1]] <= n) {
            ++ans1;
            ans2 ^= i[0] / dp[i[1]];
        }
    }
    cout << ans1 << " " << ans2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}