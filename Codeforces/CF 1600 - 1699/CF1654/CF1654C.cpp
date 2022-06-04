#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, k;
    cin >> n;
    ll s = 0, x;
    deque<ll> d;
    map<ll, ll> m;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        d.push_back(k);
        s += k;
    }
    priority_queue<ll> pq;
    pq.push(s);
    sort(d.begin(), d.end(), greater<ll>());
    while (!pq.empty() && !d.empty()) {
        x = pq.top();
        pq.pop();
        if (d.front() == x)
            d.pop_front();
        else if (d.front() > x || x < 2) {
            cout << "NO\n";
            return;
        }
        else {
            pq.push(x / 2);
            pq.push((x + 1) / 2);
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}