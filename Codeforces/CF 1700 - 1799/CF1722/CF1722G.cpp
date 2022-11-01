#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

set<int> s;

int getRand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int pick_ok() {
    while (true) {
        int x = getRand(0, (1LL << 30) - 1);
        if (s.count(x))
            continue;
        return x;
    }
}

void solve() {
    int n, x, a = 0;
    cin >> n;
    s.clear();
    for (int i = 1; i < n; ++i) {
        x = pick_ok();
        s.insert(x);
        a ^= x;
    }
    while (s.count(a)) {
        a ^= *s.begin();
        s.erase(s.begin());
        x = pick_ok();
        s.insert(x);
        a ^= x;
    }
    s.insert(a);
    for (auto i : s)
        cout << i << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}