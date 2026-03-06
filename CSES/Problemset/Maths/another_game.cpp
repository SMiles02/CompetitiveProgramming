#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n;
        bool all_even = true;
        while (n--) {
            cin >> k;
            all_even &= k % 2 == 0;
        }
        if (all_even) cout << "second\n";
        else cout << "first\n";
    }
    return 0;
}