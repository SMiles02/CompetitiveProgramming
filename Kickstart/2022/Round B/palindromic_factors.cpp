#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isPalindome(ll x) {
    vector<int> v;
    while (x) {
        v.push_back(x % 10);
        x /= 10;
    }
    int n = v.size();
    for (int i = 0; i < n; ++i)
        if (v[i] != v[n - i - 1])
            return false;
    return true;
}

void solve() {
    ll n, ans = 0;
    cin >> n;
    for (ll i = 1; i * i <= n; ++i)
        if (n % i == 0) {
            ans += isPalindome(i);
            if (i != n / i)
                ans += isPalindome(n / i);
        }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}