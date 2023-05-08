#include <bits/stdc++.h>
using namespace std;

const int S = 320;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q, cur = 0;
    cin >> q;
    vector<array<int, 3>> v(q);
    vector<int> w(q);
    map<int, int> m;
    vector<map<int, int>> block(S), every(q);
    for (int i = 0; i < q; ++i) {
        for (int j = 0; j < 3; ++j)
            cin >> v[i][j];
        w[i] = v[i][1];
    }
    sort(w.begin(), w.end());
    for (int i = 1; i < q; ++i)
        if (w[i] != w[i - 1])
            m[w[i]] = ++cur;
    for (int i = 0; i < q; ++i) {
        v[i][1] = m[v[i][1]];
        if (v[i][0] == 1) {
            ++block[v[i][1] / S][v[i][2]];
            ++every[v[i][1]][v[i][2]];
        }
        else if (v[i][0] == 2) {
            --block[v[i][1] / S][v[i][2]];
            --every[v[i][1]][v[i][2]];
        }
        else {
            int ans = 0;
            for (int j = 0; (j + 1) * S <= v[i][1]; ++j)
                if (block[j].find(v[i][2]) != block[j].end())
                    ans += block[j][v[i][2]];
            for (int j = (v[i][1] / S) * S; j <= v[i][1]; ++j)
                if (every[j].find(v[i][2]) != every[j].end())
                    ans += every[j][v[i][2]];
            cout << ans << "\n";
        }
    }
    return 0;
}