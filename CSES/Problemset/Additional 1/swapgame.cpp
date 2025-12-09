#include <bits/stdc++.h>
using namespace std;

const int P = 9;
int p[P], f[P + 1];

int get_at_position(int hash, int pos) { // pos is 0 indexed
    return (hash / p[pos]) % 10;
}

int compress(int hash) {
    vector<bool> v(10);
    int ans = 0;
    for (int i = 8; i > 0; --i) {
        int dn = 0;
        for (int j = 1; j < hash % 10; ++j)
            dn += !v[j];
        ans += f[i] * dn;
        v[hash % 10] = true;
        hash /= 10;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int base = 0, a[9];
    p[0] = 1;
    for (int i = 1; i < P; ++i)
        p[i] = p[i - 1] * 10;
    f[0] = 1;
    for (int i = 1; i <= P; ++i)
        f[i] = f[i - 1] * i;
    for (int i = 0; i < 9; ++i) {
        cin >> a[i];
        base += a[i] * p[i];
    }
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    pq.push({1, base});
    vector<int> dp(f[9]);
    dp[compress(base)] = 1;
    while (!pq.empty()) {
        auto [cur_cost, cur_hash] = pq.top();
        pq.pop();
        if (dp[compress(cur_hash)] != cur_cost)
            continue;
        for (int i = 0; i < 6; ++i) {
            int x = get_at_position(cur_hash, i), y = get_at_position(cur_hash, i + 3);
            int new_hash = cur_hash + p[i] * (y - x) + p[i + 3] * (x - y);
            int cmp = compress(new_hash);
            if (dp[cmp] == 0 || cur_cost + 1 < dp[cmp]) {
                dp[cmp] = cur_cost + 1;
                pq.push({dp[cmp], new_hash});
            }
        }
        for (int i = 0; i < 9; ++i)
            if ((i + 1) % 3 != 0) {
                int x = get_at_position(cur_hash, i), y = get_at_position(cur_hash, i + 1);
                int new_hash = cur_hash + p[i] * (y - x) + p[i + 1] * (x - y);
                int cmp = compress(new_hash);
                if (dp[cmp] == 0 || cur_cost + 1 < dp[cmp]) {
                    dp[cmp] = cur_cost + 1;
                    pq.push({dp[cmp], new_hash});
                }
            }
    }
    cout << dp[compress(987654321)] - 1;
    return 0;
}