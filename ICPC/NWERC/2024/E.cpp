#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;

ll binpow(ll a, ll b) {
    ll ans = 1, res = a;
    while (b) {
        if (b & 1) {
            ans *= res;
            ans %= n;
        }
        res *= res;
        res %= n;
        b /= 2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long k, x;
    cin >> n >> k;
    x = binpow(2, k);
    string s;
    cin >> s;
    for (long long i = 0, done = 0; done < n; ++done, i = (i + x) % n) {
        cout << s[i];
    }
    return 0;
}