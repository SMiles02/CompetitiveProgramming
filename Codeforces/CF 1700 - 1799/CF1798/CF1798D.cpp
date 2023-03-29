#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n;
    long long s = 0;
    vector<int> pos, neg;
    bool all_zero = true;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        if (k >= 0)
            pos.push_back(k);
        else
            neg.push_back(k);
        all_zero &= k == 0;
    }
    if (all_zero) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    sort(pos.rbegin(), pos.rend());
    sort(neg.rbegin(), neg.rend());
    for (int i = 0; i < n; ++i) {
        if (s >= 0 && !neg.empty()) {
            k = neg.back();
            neg.pop_back();
        }
        else {
            k = pos.back();
            pos.pop_back();
        }
        s += k;
        cout << k << " ";
    }
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