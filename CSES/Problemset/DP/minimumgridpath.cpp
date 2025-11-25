#include <bits/stdc++.h>
using namespace std;

const int N = 3003;
string s[N], ans = "";
bitset<N> done[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    vector<array<int, 2>> cur = {{0, 0}};
    while (cur.size()) {
        char smallest = 'Z';
        vector<array<int, 2>> tmp;
        for (auto [x, y] : cur) {
            smallest = min(smallest, s[x][y]);
        }
        ans += smallest;
        for (auto [x, y] : cur) {
            if (s[x][y] == smallest) {
                if (x + 1 < n && !done[x + 1][y]) {
                    tmp.push_back({x + 1, y});
                    done[x + 1][y] = 1;
                }
                if (y + 1 < n && !done[x][y + 1]) {
                    tmp.push_back({x, y + 1});
                    done[x][y + 1] = 1;
                }
            }
        }
        swap(cur, tmp);
    }
    cout << ans;
    return 0;
}