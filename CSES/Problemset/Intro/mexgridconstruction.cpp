#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            vector<bool> exists(n * 2);
            for (int k = 0; k < i; ++k) {
                exists[ans[k][j]] = true;
            }
            for (int k = 0; k < j; ++k) {
                exists[ans[i][k]] = true;
            }
            for (int k = 0; k < n * 2; ++k) {
                if (!exists[k]) {
                    ans[i][j] = k;
                    break;
                }
            }
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}