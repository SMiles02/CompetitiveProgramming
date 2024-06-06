#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

bool vector_contains(vector<ll>& v, ll n) {
    for (ll i : v) {
        if (i == n) {
            return true;
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < 60; ++i) {
        ll p = 1LL << i;
        vector<ll> v;
        for (ll x : a) {
            if (!vector_contains(v, x % p)) {
                v.push_back(x % p);
            }
        }
        if (v.size() == 2) {
            cout << p << "\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}