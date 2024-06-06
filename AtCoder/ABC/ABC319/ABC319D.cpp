#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    ll l = 1, r = 1e15, m;
    cin >> n >> k;
    vector<int> v(n);
    for (int &i : v) {
        cin >> i;
        l = max(l, (ll)i);
    }
    while (l < r) {
        m = l + (r - l) / 2;
        ll cur = 0, fill = m;
        for (int i : v) {
            if (fill + i + 1 > m) {
                ++cur;
                fill = i;
            }
            else {
                fill += i + 1;
            }
        }
        if (cur > k) {
            l = m + 1;
        }
        else {
            r = m;
        }
    }
    cout << l;
    return 0;
}