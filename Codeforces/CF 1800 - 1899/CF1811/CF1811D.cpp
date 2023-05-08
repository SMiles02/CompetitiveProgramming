// note: i hate this problem, upsolve eventually when i feel like shit

#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 50;
ll f[N];

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    if ((f[n] & 1) && (x == 1 || x == f[n]) && (y <= 2 || y >= f[n + 1] - 1))
        cout << "YES\n";
    else if ((f[n] % 2 == 0) && (y == 1 || y == f[n + 1]) && (x <= 2 || x >= f[n] - 1))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    f[0] = f[1] = 1;
    for (int i = 2; i < N; ++i)
        f[i] = f[i - 1] + f[i - 2];
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}