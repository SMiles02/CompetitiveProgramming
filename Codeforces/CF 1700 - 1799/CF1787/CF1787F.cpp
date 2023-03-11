#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ans = 0, tot = 0;
    double d = 0;
    const int IT = 1e7, MX = 1e6;
    for (int i = 0; i < IT; ++i) {
        int x = uniform_int_distribution<int>(1, MX)(rng);
        int y = uniform_int_distribution<int>(-MX, MX)(rng);
        d += 1LL * y * y;
    }
    cout << sqrt(d / IT) / MX;
    return 0;
}