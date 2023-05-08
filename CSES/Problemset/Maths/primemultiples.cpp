#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, ans = 0;
    int k;
    cin >> n >> k;
    vector<ll> a(k);
    for (auto &i : a)
        cin >> i;
    for (int i = 1; i < (1 << k); ++i) {
        ll cur = 1;
        bool prod_too_big = false;
        for (int j = 0; j < k; ++j)
            if (((1 << j) & i)) {
                if ((n + cur - 1) / cur > a[j])
                    cur *= a[j];
                else
                    prod_too_big = true;
            }
        if (!prod_too_big) {
            if (__builtin_popcount(i) & 1)
                ans += n / cur;
            else
                ans -= n / cur;
        }
    }
    cout << ans;
    return 0;
}