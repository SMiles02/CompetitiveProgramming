#include <bits/stdc++.h>
using namespace std;

const string S = "win";
int cur[3];
vector<int> cnt[3][3];

void solve() {
    int n;
    cin >> n;
    string s;
    for (int i = 1; i <= n; ++i) {
        cur[0] = cur[1] = cur[2] = 0;
        cin >> s;
        for (auto j : s) {
            if (j == 'w')
                ++cur[0];
            else if (j == 'i')
                ++cur[1];
            else
                ++cur[2];
        }
        for (int x = 0; x < 3; ++x)
            for (int y = 0; y < 3; ++y)
                if (cur[x] > 1 && cur[y] < 1) {
                    --cur[x];
                    ++cur[y];
                    cnt[x][y].push_back(i);
                }
    }
    vector<array<int, 4>> ans;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            while (!cnt[i][j].empty() && !cnt[j][i].empty()) {
                ans.push_back({cnt[i][j].back(), i, cnt[j][i].back(), j});
                cnt[i][j].pop_back();
                cnt[j][i].pop_back();
            }
    for (int x = 0; x < 3; ++x)
        for (int y = 0; y < 3; ++y)
            while (!cnt[x][y].empty()) {
                ans.push_back({cnt[x][y].back(), x, cnt[y][3 - x - y].back(), y});
                ans.push_back({cnt[y][3 - x - y].back(), x, cnt[3 - x - y][x].back(), 3 - x - y});
                cnt[x][y].pop_back();
                cnt[y][3 - x - y].pop_back();
                cnt[3 - x - y][x].pop_back();
            }
    cout << ans.size() << "\n";
    for (auto i : ans)
        cout << i[0] << " " << S[i[1]] << " " << i[2] << " " << S[i[3]] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}