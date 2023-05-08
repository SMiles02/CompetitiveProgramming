#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct S {
    int cnt;
    ll sm;
    bool operator!=(const S& rhs) const {
        return !(cnt == rhs.cnt && sm == rhs.sm);
    }
    bool operator<(const S& rhs) const {
        return cnt < rhs.cnt || (cnt == rhs.cnt && sm < rhs.sm);
    }
    S operator+(const S& rhs) const {
        return {cnt + rhs.cnt, sm + rhs.sm};
    }
};

const int N = 1001, D = 7000;
S dp[N][D];
vector<array<ll, 2>> primes;
vector<int> v;
vector<vector<int>> factorisations;

void gen_factors(int i) {
    if (i == primes.size()) {
        factorisations.push_back(v);
        return;
    }
    v[i] = 0;
    for (int j = 0; j <= primes[i][1]; ++j) {
        gen_factors(i + 1);
        ++v[i];
    }
}

int get_factorisation_order(int n) {
    int ans = 0, m = factorisations.size();
    for (int i = 0; i < primes.size(); ++i) {
        int cur = 0;
        while (n % primes[i][0] == 0) {
            n /= primes[i][0];
            ++cur;
        }
        m /= primes[i][1] + 1;
        ans += m * cur;
    }
    return ans;
}

int complement_factor(int x, int y) {
    int ans = 0, m = factorisations.size();
    for (int i = 0; i < primes.size(); ++i) {
        m /= primes[i][1] + 1;
        ans += m * max(factorisations[x][i] - factorisations[y][i], 0);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    ll k, x;
    cin >> n >> k;
    if (k == 1) {
        array<ll, 2> a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i][0];
            a[i][1] = i;
        }
        sort(a, a + n);
        cout << "1\n" << a[0][1] + 1;
        return 0;
    }
    x = k;
    for (int i = 2; 1LL * i * i <= x; ++i)
        if (x % i == 0) {
            primes.push_back({i, 0});
            while (x % i == 0) {
                ++primes.back()[1];
                x /= i;
            }
        }
    if (x > 1)
        primes.push_back({x, 1});
    v.resize(primes.size());
    gen_factors(0);
    ll a[n + 1];
    for (int j = 0; j < factorisations.size(); ++j)
        dp[0][j] = {n + 1, 0};
    dp[0][0] = {0, 0};
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        int cur = get_factorisation_order(__gcd(a[i], k));
        for (int j = 0; j < factorisations.size(); ++j)
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][complement_factor(j, cur)] + S{1, a[i]});
    }
    if (dp[n][factorisations.size() - 1].cnt > n) {
        cout << -1;
        return 0;
    }
    cout << dp[n][factorisations.size() - 1].cnt << "\n";
    int cur = factorisations.size() - 1;
    for (int i = n; i >= 1; --i)
        if (dp[i][cur] != dp[i - 1][cur]) {
            cout << i << " ";
            cur = complement_factor(cur, get_factorisation_order(__gcd(a[i], k)));
        }
    return 0;
}