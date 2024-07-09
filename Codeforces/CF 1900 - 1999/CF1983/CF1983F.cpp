#include <bits/stdc++.h>
using namespace std;

struct trie {
    int l, c;
    vector<array<int, 2>> node;
    vector<int> max_id;
    trie(int l, int max_members) : l(l), c(0), node((l + 2) * max_members + 3), max_id((l + 2) * max_members + 3) {}
    void add(int x, int id) {
        int cur = 0;
        for (int i = l; i >= 0; --i) {
            bool has_bit = (1 << i) & x;
            if (!node[cur][has_bit]) {
                node[cur][has_bit] = ++c;
            }
            cur = node[cur][has_bit];
            max_id[cur] = id;
        }
    }
    int find_max(int x, int y) {
        int cur = 0, ans = -1;
        for (int i = l; i >= 0; --i) {
            bool has_bit = (1 << i) & (x ^ y);
            if (((1 << i) & y) && node[cur][!has_bit]) {
                ans = max(ans, max_id[node[cur][!has_bit]]);
            }
            if (!node[cur][has_bit]) {
                break;
            }
            cur = node[cur][has_bit];
            if (i == 0) {
                ans = max(ans, max_id[cur]);
            }
        }
        return ans;
    }
};

const int L = 30;

long long check(vector<int>& v, int n, int k) {
    trie t(L, n + 1);
    int maxi = -1;
    long long cnt = 0;
    for (int i = 1; i < n; ++i) {
        t.add(v[i - 1], i - 1);
        maxi = max(maxi, t.find_max(v[i], k));
        cnt += maxi + 1;
    }
    return cnt;
}

void solve() {
    int n, ans = (1 << L) - 1;
    long long k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = L - 1; i >= 0; --i) {
        if (check(v, n, ans ^ (1 << i)) >= k) {
            ans ^= 1 << i;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}