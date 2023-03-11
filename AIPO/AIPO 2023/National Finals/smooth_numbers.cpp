// please use 10^7 notation and not 100000000000000000000000000000000000000000000000000000000000000000000000

#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e7 + 1, K = 1e3 + 1;
bitset<N> dp;
bitset<K> sieve;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, ans = 1;
    cin >> k >> n;
    vector<int> primes;
    for (int i = 2; i <= k; ++i)
        if (!sieve[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= k; j += i)
                sieve[j] = 1;
        }
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j : primes)
            if (i % j == 0 && dp[i / j])
                dp[i] = 1;
        ans += dp[i];
    }
    cout << ans;
    return 0;
}