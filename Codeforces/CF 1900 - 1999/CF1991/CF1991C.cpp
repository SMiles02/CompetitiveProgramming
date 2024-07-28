#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

void solve() {
    int n;
    cin >> n;
    set<int> s;
    vector<int> ans;
    for (int i = 0, k; i < n; ++i) {
        cin >> k;
        s.insert(k);
    }
    while (s.size() > 1 && ans.size() <= 40) {
        int m = (*s.begin() + *(--s.end())) / 2;
        set<int> t;
        for (int i : s) {
            t.insert(abs(i - m));
        }
        swap(s, t);
        ans.push_back(m);
    }
    if (*s.begin() != 0) {
        ans.push_back(*s.begin());
    }
    if (ans.size() > 40) {
        cout << "-1\n";
        return;
    }
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
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