#include <bits/stdc++.h>
using namespace std;

const int N = 3001;
int dpl[N][N], dpu[N][N], dps[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int k = 0; k < m; ++k) {
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1][j - 1] != 'A' + k) {
                    dpl[i][j] = dpu[i][j] = dps[i][j] = 0;
                    continue;
                }
                dpl[i][j] = dpl[i][j - 1] + 1;
                dpu[i][j] = dpu[i - 1][j] + 1;
                ans += dps[i][j] = min({dpl[i][j - 1], dpu[i - 1][j], dps[i - 1][j - 1]}) + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}