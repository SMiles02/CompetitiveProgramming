#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
bitset<N> not_square_free;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 2; 1LL * i * i <= N; ++i)
        for (int j = i * i; j <= N; j += i * i)
            not_square_free[j] = 1;
    int t, n, cnt;
    cin >> t;
    cin >> n;
    cnt = n;
    vector<int> a(n + 1), p(n + 2);
    a[0] = 4;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt -= not_square_free[a[i]];
        p[i] = p[i - 1] + 1 - not_square_free[a[i]];
    }
    if (t == 1) {
        cout << cnt;
    }
    else {
        int ans = -1, cur = 0;
        vector<int> v;
        vector<array<int, 2>> w;
        for (int i = 1; i <= n; ++i) {
            if (!not_square_free[a[i]]) {
                if (!not_square_free[a[i - 1]])
                    ++v.back();
                else
                    v.push_back(1);
                if (v.size() > 1 && !not_square_free[a[i - v.back() - 1]]) {
                    int cur_ans = v.back() + v[v.size() - 2];
                    if (cur_ans > ans) {
                        ans = cur_ans;
                        w.clear();
                    }
                    if (cur_ans == ans) {
                        w.push_back({i - cur_ans, i});
                    }
                }
            }
        }
        if (ans == -1) {
            cout << ans;
            return 0;
        }
        cout << ans << " " << w.size() << "\n";
        for (auto j : w)
            cout << j[0] << " " << j[1] << "\n";
    }
    return 0;
}