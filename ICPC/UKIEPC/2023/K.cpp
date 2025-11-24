#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, x = 0, y = 0;
    cin >> n >> m;
    vector<bool> v(m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            ++x;
        }
        else {
            ++y;
            v[i] = true;
        }
    }
    cout << "YES\n" << max(x, y) << "\n";
    for (int i = 0; i < m; ++i) {
        if (x >= y && !v[i]) {
            cout << i + 1 << " ";
        }
        else if (x < y && v[i]) {
            cout << i + 1 << " ";
        }
    }
    return 0;
}