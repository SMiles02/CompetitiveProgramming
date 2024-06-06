#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b, c, d, e, f;
    cin >> a >> b >> c;
    cin >> d >> e >> f;
    for (int i = 0; i <= 1e6; ++i) {
        if (i % c == 0) {
            d -= b;
        }
        if (i % f == 0) {
            a -= e;
        }
        if (a <= 0 && d <= 0) {
            cout << "draw";
            return 0;
        }
        if (a <= 0) {
            cout << "player two";
            return 0;
        }
        if (d <= 0) {
            cout << "player one";
            return 0;
        }
    }
    return 0;
}