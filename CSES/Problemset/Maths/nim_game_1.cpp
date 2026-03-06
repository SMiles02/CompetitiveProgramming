#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n, x = 0, k;
        cin >> n;
        while (n--) {
            cin >> k;
            x ^= k;
        }
        if (x == 0) cout << "second\n";
        else cout << "first\n";
    }
    return 0;
}