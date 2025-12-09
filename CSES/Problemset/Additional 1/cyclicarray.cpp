#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 1, L = 21;
int a[N], up[L][N * 2];
ll p[N * 2];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, ans = N;
    ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = a[i];
        p[i + n] = a[i];
    }
    for (int i = 1; i <= n * 2; ++i)
        p[i] += p[i - 1];
    for (int i = 0; i < L; ++i)
        up[i][n * 2 + 1] = n * 2;
    for (int i = n * 2; i > 0; --i) {
        int l = i, r = n * 2 - 1, m;
        while (l < r) {
            m = l + (r - l) / 2 + 1;
            if (p[m] - p[i - 1] <= k)
                l = m;
            else
                r = m - 1;
        }
        up[0][i] = l;
        for (int j = 1; j < L; ++j)
            up[j][i] = up[j - 1][up[j - 1][i] + 1];
    }
    for (int i = 1; i <= n; ++i) {
        int cur_pos = i, cur_ans = 0;
        for (int j = L - 1; j >= 0; --j)
            if (up[j][cur_pos] < i + n - 1) {
                cur_ans += 1 << j;
                cur_pos = up[j][cur_pos] + 1;
            }
        ans = min(ans, cur_ans + 1);
    }
    cout << ans;
    return 0;
}