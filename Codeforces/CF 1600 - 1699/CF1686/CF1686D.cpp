#include <bits/stdc++.h>
using namespace std;

struct clean_set {
    multiset<int> m;
    void push(int x) {
        if (x > 1)
            m.insert(x);
    }
    void remove(int x) {
        m.erase(m.find(x));
    }
    bool empty() {
        return m.empty();
    }
    void clear() {
        m.clear();
    }
    int big() {
        return *(--m.end());
    }
    int smol() {
        return *m.begin();
    }
    bool exists_at_least(int x) {
        return m.lower_bound(x) != m.end();
    }
    int lower_bound(int x) {
        return *m.lower_bound(x);
    }
};

int f(int l, int r) {
    return r - l + 1;
}

void solve() {
    int n, a, b, c, d, x = 0, y = 0, cur = 0, p;
    cin >> a >> b >> c >> d;
    string s;
    cin >> s;
    n = s.size();
    for (auto i : s) {
        x += (i == 'A');
        y += (i == 'B');
    }
    if (a + c + d != x || b + c + d != y) {
        cout << "NO\n";
        return;
    }
    clean_set ab, ba, aba, bab;
    for (int i = 1; i < n; ++i)
        if (s[i] == s[i - 1]) {
            if (s[i - 1] == s[cur]) {
                if (s[cur] == 'A')
                    aba.push(f(cur, i - 1));
                else
                    bab.push(f(cur, i - 1));
            }
            else {
                if (s[cur] == 'A')
                    ab.push(f(cur, i - 1));
                else
                    ba.push(f(cur, i - 1));
            }
            cur = i;
        }
    if (cur != n) {
        if (s[n - 1] == s[cur]) {
            if (s[cur] == 'A')
                aba.push(f(cur, n - 1));
            else
                bab.push(f(cur, n - 1));
        }
        else {
            if (s[cur] == 'A')
                ab.push(f(cur, n - 1));
            else
                ba.push(f(cur, n - 1));
        }
    }
    while (c > 0) {
        if (!ab.empty()) {
            --c;
            p = ab.smol();
            ab.remove(p);
            ab.push(p - 2);
        }
        else if (!aba.empty()) {
            --c;
            p = aba.smol();
            aba.remove(p);
            aba.push(p - 2);
        }
        else if (!bab.empty()) {
            --c;
            p = bab.smol();
            bab.remove(p);
            bab.push(p - 2);
        }
        else if (ba.exists_at_least(3)) {
            --c;
            p = ba.lower_bound(3);
            ba.remove(p);
            aba.push(p - 3);
        }
        else
            break;
    }
    while (d > 0) {
        if (!ba.empty()) {
            --d;
            p = ba.smol();
            ba.remove(p);
            ba.push(p - 2);
        }
        else if (!aba.empty()) {
            --d;
            p = aba.smol();
            aba.remove(p);
            aba.push(p - 2);
        }
        else if (!bab.empty()) {
            --d;
            p = bab.smol();
            bab.remove(p);
            bab.push(p - 2);
        }
        else if (ab.exists_at_least(3)) {
            --d;
            p = ab.lower_bound(3);
            ab.remove(p);
            bab.push(p - 3);
        }
        else
            break;
    }
    if (c <= 0 && d <= 0) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}