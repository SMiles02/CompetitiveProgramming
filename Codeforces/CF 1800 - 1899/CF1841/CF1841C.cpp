#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

vector<int> p10 = {1, 10, 100, 1000, 10000};

void solve() {
    string s;
    cin >> s;
    int n = s.size(), ans, score = 0;
    int a[n + 1], b[n + 1];
    vector<int> r(5);
    vector<vector<int>> p(n + 2, vector<int>(5));
    for (int i = 1; i <= n; ++i) {
        a[i] = s[i - 1] - 'A';
        r[a[i]] = i;
        for (int j = 0; j < 5; ++j)
            p[i][j] = p[i - 1][j];
        ++p[i][a[i]];
    }
    p[n + 1] = p[n];
    vector<vector<int>> suff(5), only_barrier(n + 1, vector<int>(5));
    vector<int> zeroes(5);
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = a[i] + 1; j < 5; ++j)
            cnt += p[n][j] - p[i][j];
        if (cnt == 0) {
            b[i] = p10[a[i]];
        }
        else {
            b[i] = -p10[a[i]];
        }
        score += b[i];
        if (cnt == 1) {
            for (int j = a[i] + 1; j < 5; ++j)
                if (r[j] > i)
                    ++only_barrier[r[j]][a[i]];
        }
    }
    ans = score;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 5; ++j) {
            int cur = score;
            cur -= b[i];
            int cnt = 0;
            for (int k = j + 1; k < 5; ++k)
                cnt += p[n][j] - p[i][j];
            if (cnt == 0)
                cur += p10[j];
            else
                cur -= p10[j];
            for (int k = j; k < a[i]; ++k)
                cur += 2LL * only_barrier[i][k] * p10[k];
            for (int k = 0; k < j; ++k)
                cur -= 2LL * zeroes[k] * p10[k];
            ans = max(ans, cur);
        }
        if (b[i] > 0)
            ++zeroes[a[i]];
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}