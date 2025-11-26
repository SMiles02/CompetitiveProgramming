#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> digit_vector(ll n) {
    if (n == 0) {
        return {0};
    }
    vector<int> v;
    while (n > 0) {
        v.push_back(n % 10);
        n /= 10;
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll a, b, lo = 0, hi = 0;
    cin >> a >> b;
    bool all_same = true, all_zero = true;
    vector<int> v = digit_vector(a), w = digit_vector(b);
    vector<ll> dp(10);
    while (v.size() < w.size()) {
        v.push_back(0);
    }
    reverse(v.begin(), v.end());
    reverse(w.begin(), w.end());
    for (int i = 0; i < v.size(); ++i) {
        all_zero &= v[i] == 0;
        if (all_same && v[i] != w[i]) {
            all_same = false;
            lo = !(i > 0 && v[i] == v[i - 1]);
            hi = !(i > 0 && w[i] == w[i - 1]);
            for (int j = v[i] + 1; j < w[i]; ++j) {
                dp[j] = 1;
            }
            continue;
        }
        if (all_same && i > 0 && v[i] == v[i - 1]) {
            cout << 0;
            return 0;
        }
        if (!all_same) {
            vector<ll> new_dp(10);
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    if (j != k) {
                        new_dp[j] += dp[k];
                    }
                }
                if (v[i] < j && !(i > 0 && v[i - 1] == j)) {
                    new_dp[j] += lo;
                }
                if (j < w[i] && !(i > 0 && w[i - 1] == j)) {
                    new_dp[j] += hi;
                }
            }
            if (v[i] == v[i - 1] && !all_zero) {
                lo = 0;
            }
            if (w[i] == w[i - 1]) {
                hi = 0;
            }
            swap(dp, new_dp);
        }
    }
    if (a == b) {
        cout << 1;
    }
    else {
        ll sum = lo + hi;
        for (int i = 0; i < 10; ++i) {
            sum += dp[i];
        }
        cout << sum;
    }
    return 0;
}