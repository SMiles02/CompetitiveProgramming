#include <bits/stdc++.h>
#define ll long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 201, MX = 1e9;
ll a[N][N];

ll random_ll() {
    return 1LL * MX * uniform_int_distribution<int>(1, MX)(rng) + uniform_int_distribution<int>(1, MX)(rng);
}

void gen_grid() {
    int n = 200, m = 200;
    ll random_num;
    while (true) {
        set<ll> s;
        for (int i = 0; i < m; ++i) {
            random_num = random_ll();
            while (s.count(random_num))
                random_num = random_ll();
            a[0][i] = random_num;
            s.insert(random_num);
        }
        for (int i = 1; i < n; ++i) {
            while (true) {
                random_num = random_ll();
                bool ok = true;
                for (int j = 0; j < m; ++j)
                    ok |= s.count(a[i - 1][j] ^ a[i - 1][0] ^ random_num) == 0;
                if (ok)
                    break;
            }
            for (int j = 0; j < m; ++j) {
                a[i][j] = a[i - 1][j] ^ a[i - 1][0] ^ random_num;
                s.insert(a[i][j]);
            }
        }
        break;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    cout << n * m << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    gen_grid();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}