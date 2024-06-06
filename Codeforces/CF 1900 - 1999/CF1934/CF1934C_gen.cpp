#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getrand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 20;
    cout << t << endl;
    while (t--) {
        int n, m, a, b, c, d;
        n = getrand(2, 20); m = getrand(2, 20);
        a = getrand(1, n); b = getrand(1, m);
        c = getrand(1, n); d = getrand(1, m);
        cout << n << " " << m << "\n";
        cout << a << " " << b << " " << c << " " << d << "\n";
    }
    return 0;
}