#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

const int N = 1e6 + 4, L = 21;
int a[N * 2], up[L][N * 2];
ll p[N * 2];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= n * 2 + 1; ++i) {
        p[i] = p[i - 1] + a[i];
    }
    for (int j = 0; j < L; ++j) {
        up[j][n * 2 + 1] = -1;
    }
    for (int i = n * 2; i > 0; --i) {
        if (p[n * 2] - p[i - 1] < c) {
            up[0][i] = -1;
            continue;
        }
        int l = i, r = n * 2, m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (p[m] - p[i - 1] < c) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        up[0][i] = l;
    }
    for (int j = 1; j < L; ++j) {
        for (int i = 1; i <= n * 2; ++i) {
            if (up[j - 1][i] == -1 || up[j - 1][up[j - 1][i] + 1] == -1) {
                up[j][i] = -1;
            }
            else {
                up[j][i] = up[j - 1][up[j - 1][i] + 1];
            }
        }
    }
    // for (int i = 1; i <= n * 2; ++i) {
    //     for (int j = 0; j < L; ++j) {
    //         cout << up[j][i] << " ";
    //     }
    //     cout << "\n";
    // }
    for (int i = 1; i <= n; ++i) {
        int cur = i, ans = 0;
        for (int j = L - 1; j >= 0; --j) {
            if (up[j][cur] < i + n && up[j][cur] != -1) {
                ans += 1 << j;
                cur = up[j][cur] + 1;
                // cout << "up " << (1 << j) << "\n";
            }
        }
        if (cur == i + n) {
            --ans;
        }
        cout << ans << " ";
    }
    return 0;
}