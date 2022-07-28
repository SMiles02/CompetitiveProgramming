#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, zero = 0;
    vector<int> pos, neg, a;
    cin >> n;
    while (n--) {
        cin >> x;
        if (x > 0)
            pos.push_back(x);
        else if (x < 0)
            neg.push_back(x);
        else
            ++zero;
    }
    if (max(pos.size(), neg.size()) > 2) {
        cout << "NO\n";
        return;
    }
    for (int i : pos)
        a.push_back(i);
    for (int i : neg)
        a.push_back(i);
    for (int i = 0; i < min(zero, 3); ++i)
        a.push_back(0);
    set<int> s;
    for (int i : a)
        s.insert(i);
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < i; ++j)
            for (int k = 0; k < j; ++k)
                if (!s.count(a[i] + a[j] + a[k])) {
                    cout << "NO\n";
                    return;
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