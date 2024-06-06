#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, w, o;
    cin >> n >> w;
    if (w > 5000) {
        o = -1;
    }
    else {
        o = 1;
    }
    if (n < 9) {
        for (int i = 0; i < n; ++i) {
            cout << w + (n - i) * o << " " << i << "\n";
        }
        return 0;
    }
    for (int i = 0; i < (n + 1) / 2; ++i) {
        cout << w + o * i << " " << i + 1 << "\n";
    }
    for (int i = 0; i < n / 2; ++i) {
        cout << w << " " << 1000 - i << "\n";
    }
    return 0;
}