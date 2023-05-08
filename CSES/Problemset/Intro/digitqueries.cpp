#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n, cur = 1, len = 1, x;
    cin >> n;
    while (cur * len * 9 < n) {
        n -= cur * len * 9;
        cur *= 10;
        ++len;
    }
    // [1, len] => cur
    // [len + 1, len * 2] => cur + 1
    // [len * 2 + 1, len * 3] => cur + 2
    x = (n - 1) / len;
    cur += x;
    n -= x * len;
    vector<int> v;
    while (cur > 0) {
        v.push_back(cur % 10);
        cur /= 10;
    }
    cout << v[v.size() - n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}