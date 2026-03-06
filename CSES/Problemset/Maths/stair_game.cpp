#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, a, x = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a;
            if (i & 1) x ^= a;
        }
        if (x == 0) cout << "second\n";
        else cout << "first\n";
    }
    return 0;
}