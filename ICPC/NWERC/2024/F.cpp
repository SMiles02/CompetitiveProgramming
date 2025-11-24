#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), c(n), head(n), v = {};
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        while (!v.empty() && c[i] > c[v.back()]) {
            v.pop_back();
        }
        if (v.empty()) {
            head[i] = -1;
        }
        else {
            head[i] = v.back();
        }
        v.push_back(i);
    }
    while (q--) {
        char t;
        cin >> t;
        if (t == '?') {
            int l;
            cin >> l;
            cout << a[l - 1] << "\n";
        }
        else {
            int l, x;
            cin >> l >> x;
            --l;
            vector<int> w;
            while (x > 0 && l != -1) {
                int cur = min(c[l] - a[l], x);
                a[l] += cur;
                x -= cur;
                if (a[l] == c[l]) {
                    w.push_back(l);
                    l = head[l];
                }
            }
            for (int i : w) {
                head[i] = l;
            }
        }
    }
    return 0;
}