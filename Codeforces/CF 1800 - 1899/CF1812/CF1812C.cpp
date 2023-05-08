#include <bits/stdc++.h>
using namespace std;

string pi = "3141592653589793238462643383279502884197";

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int ans = 1;
        for (int j = 0; j < pi[i] - '0'; ++j) {
            int k;
            cin >> k;
            ans *= k;
        }
        cout << ans << "\n";
    }
    return 0;
}