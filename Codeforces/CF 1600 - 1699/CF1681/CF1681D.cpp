#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

vector<int> digits(ll n) {
    vector<int> v;
    while (n) {
        if (n % 10 > 1)
            v.push_back(n % 10);
        n /= 10;
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, x, a, b;
    vector<int> v;
    cin >> n >> x;
    n = binpow(10, n - 1);
    queue<array<ll, 2>> q;
    q.push({x, 0});
    set<ll> done;
    while (!q.empty()) {
        a = q.front()[0];
        b = q.front()[1];
        q.pop();
        if (a >= n) {
            cout << b;
            return 0;
        }
        v = digits(a);
        for (int i : v)
            if (done.count(a * i) == 0) {
                done.insert(a * i);
                q.push({a * i, b + 1});
            }
    }
    cout << -1;
    return 0;
}