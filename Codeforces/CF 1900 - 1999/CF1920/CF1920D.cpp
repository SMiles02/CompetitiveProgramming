#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll safe_mul(ll a, ll b) {
    if (__lg(a) + __lg(b) < (double)62) {
        return a * b;
    }
    return 1LL << 62;
}

void solve() {
    int n, q, c = 0;
    cin >> n >> q;
    vector<vector<int>> a(n + 5);
    vector<ll> v(n + 5);
    a[0].push_back(-1);
    while (n--) {
        int b, x;
        cin >> b >> x;
        if (b == 1) {
            if (a[c][0] < 0) {
                ++c;
                v[c] = v[c - 1];
            }
            a[c].push_back(x);
            ++v[c];
        }
        else if (v[c] < 1e18) {
            a[++c].push_back(-x - 1);
            v[c] = safe_mul(v[c - 1], x + 1);
        }
    }
    while (q--) {
        ll k;
        cin >> k;
        --k;
        for (int i = c; i >= 1; --i) {
            k %= v[i];
            if (a[i][0] > 0 && k >= v[i - 1]) {
                cout << a[i][k - v[i - 1]] << " ";
                break;
            }
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}