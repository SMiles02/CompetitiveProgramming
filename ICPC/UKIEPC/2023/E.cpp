#include <bits/stdc++.h>
#define ll long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 31, K = 1e7, INF = 1e9;
int n, grid[N][N];
bitset<N> on, best_con;

int get_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

double rnd() { return double(get_rand(1, INF)) / INF; }

int main() {
    string s;
    cin >> s;
    n = s.size();
    ll ans = 0, best = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            cin >> grid[i][j];
            grid[j][i] = grid[i][j];
        }
    }
    // for (int i = 0; i < n; ++i) {
    //     for (int j = i; j < n; ++j) {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for (int i = 0; i < n; ++i) {
        // if (1021 & (1 << i)) {
        if (get_rand(0, 1)) {
            on[i] = 1;
            for (int j = 0; j <= i; ++j) {
                if (on[j]) {
                    ans += grid[i][j];
                }
            }
        }
    }
    if (ans > best) {
        best = ans;
        best_con = on;
    }
    double t = 1e6, mpl = pow((1e-5) / t, (double) 1 / K);
    for (int i = 0; i < K && ans < n; i++) {
        t *= mpl;
        ll new_val = ans;
        int x = get_rand(0, n - 1);
        if (on[x]) {
            for (int i = 0; i < n; ++i) {
                if (on[i]) {
                    new_val -= grid[x][i];
                }
            }
        }
        else {
            for (int i = 0; i < n; ++i) {
                if (on[i]) {
                    new_val += grid[x][i];
                }
            }
            new_val += grid[x][x];
        }
        if (new_val > ans || rnd() < exp((new_val - ans) / t)) {
            ans = new_val;
            on[x] = 1 - on[x];
        }
        if (ans > best) {
            best = ans;
            best_con = on;
        }
    }
    cout << best_con.count() << "\n";
    for (int i = 0; i < n; ++i) {
        if (best_con[i]) {
            cout << s[i];
        }
    }
    cerr << ans << "\n";
    return 0;
}
