#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int l = 1, r = 1e9, m;
    while (l < r) {
        m = l + (r - l) / 2;
        cout << "? " << m << endl;
        string s;
        cin >> s;
        if (s[0] == 'Y') {
            l = m + 1;
        }
        else {
            r = m;
        }
    }
    cout << "! " << l << endl;
    return 0;
}