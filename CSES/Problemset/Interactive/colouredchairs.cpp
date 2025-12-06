
#include <bits/stdc++.h>
using namespace std;

bool local = false;
string s;

char make_query(int i) {
    cout << "? " << i << endl;
    if (local) {
        cout << s[i - 1] << endl;
        return s[i - 1];
    }
    char c;
    cin >> c;
    return c;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int l = 1, r, m;
    cin >> r;
    if (local) {
        cin >> s;
    }
    char a = make_query(1), b = make_query(r), c;
    if (a == b) {
        cout << "! " << r << endl;
        return 0;
    }
    while (l + 1 < r) {
        m = l + (r - l) / 2;
        c = make_query(m);
        if (((l & 1) == (m & 1)) ^ (a == c)) {
            r = m;
            b = c;
        }
        else {
            l = m;
            a = c;
        }
    }
    cout << "! " << l << endl;
    return 0;
}