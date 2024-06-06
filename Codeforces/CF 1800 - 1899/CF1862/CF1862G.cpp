#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n;
    int a[n + 1];
    map<int, int> m;
    set<int> s;
    multiset<int> diffs;
    diffs.insert(0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++m[a[i]];
        s.insert(a[i]);
    }
    int last = *s.begin();
    for (auto i : s) {
        if (i == last) {
            continue;
        }
        diffs.insert(i - last);
        last = i;
    }
    cin >> q;
    if (n == 1) {
        while (q--) {
            int t, x;
            cin >> t >> x;
            a[t] = x;
            cout << a[1] << " ";
        }
        cout << "\n";
        return;
    }
    while (q--) {
        int t, x;
        cin >> t >> x;
        if (--m[a[t]] == 0) {
            if (s.upper_bound(a[t]) == s.end()) {
                diffs.erase(diffs.find(a[t] - *(--s.find(a[t]))));
            }
            else if (*s.begin() == a[t]) {
                diffs.erase(diffs.find(*(s.upper_bound(a[t])) - a[t]));
            }
            else {
                diffs.erase(diffs.find(*s.upper_bound(a[t]) - a[t]));
                diffs.erase(diffs.find(a[t] - *(--s.find(a[t]))));
                diffs.insert(*s.upper_bound(a[t]) - *(--s.find(a[t])));
            }
            s.erase(a[t]);
        }
        if (++m[x] == 1) {
            if (x < *s.begin()) {
                diffs.insert(*s.begin() - x);
            }
            else if (*(--s.end()) < x) {
                diffs.insert(x - *(--s.end()));
            }
            else {
                diffs.erase(diffs.find(*s.upper_bound(x) - *(--s.lower_bound(x))));
                diffs.insert(*s.upper_bound(x) - x);
                diffs.insert(x - *(--s.lower_bound(x)));
            }
            s.insert(x);
        }
        a[t] = x;
        cout << *(--s.end()) + *(--diffs.end()) << " ";
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