#include <bits/stdc++.h>
using namespace std;

bool local = 0;
int n, initial, a;

int query(int c) {
    cout << "+ " << c << endl;
    a += c;
    int x;
    if (local)
        return (initial + a) / n;
    cin >> x;
    return x;
}
  
int main() {
    int c, k, q, v, l, r, m;
    cin >> n;
    if (local)
        cin >> initial;
    if (n < 10) {
        int d = 0, e = 1;
        while (d != e) {
            e = query(n - 1);
            swap(d, e);
        }
        cout << "! " << (d + 1) * n - 1 << endl;
        return 0;
    }
    l = 1;
    r = n - 1;
    while (l < r) {
        m = l + (r - l) / 2 + 1;
        c = m + a;
        k = (c / n) * n;
        if (c == k) {
            --m;
            --c;
            k -= n;
        }
        q = k + n - c;
        v = query(q);
        if (v == k / n)
            r = m - 1;
        else
            l = m;
    }
    cout << "! " << l + a << endl;
    return 0;
}