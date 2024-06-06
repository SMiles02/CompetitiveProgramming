#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll k, b, n, t, cur = 1, turns = 0;
    cin >> k >> b >> n >> t;
    while (cur < t) {
        cur = cur * k + b;
        ++turns;
    }
    if (turns > n) {
        cout << "0\n";
        return 0;
    }
    while (t < cur) {
        t = t * k + b;
        --turns;
    }
    cout << n - turns;
    return 0;
}