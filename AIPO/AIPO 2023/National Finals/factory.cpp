#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 501, P = 14;
int hash_val[N], rev_hash[N];
ll p[P];

int get_at_position(ll hash, int pos) { // pos is 0 indexed
    return (hash / p[pos]) % 10;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, cur = 0;
    ll base = 0, trg = 0;
    cin >> n >> m;
    int a[n][m], b[n][m];
    map<ll, int> dp;
    set<int> s;
    p[0] = 1;
    for (int i = 1; i < P; ++i)
        p[i] = p[i - 1] * 10;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            s.insert(a[i][j]);
        }
    for (int i : s) {
        hash_val[i] = cur;
        rev_hash[cur] = i;
        ++cur;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            base += hash_val[a[i][j]] * p[m * i + j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
            trg += hash_val[b[i][j]] * p[m * i + j];
        }
    if (base == trg) {
        cout << "0\n";
        return 0;
    }
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
    pq.push({1, base});
    dp[base] = 1;
    while (!pq.empty()) {
        ll cur_hash = pq.top()[1];
        int cur_cost = pq.top()[0];
        pq.pop();
        if (dp[cur_hash] != cur_cost)
            continue;
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                int x = get_at_position(cur_hash, (i - 1) * m + j), y = get_at_position(cur_hash, i * m + j);
                ll new_hash =  cur_hash + p[(i - 1) * m + j] * (y - x) + p[i * m + j] * (x - y);
                if (dp[new_hash] == 0 || cur_cost + rev_hash[x] + rev_hash[y] < dp[new_hash]) {
                    dp[new_hash] = cur_cost + rev_hash[x] + rev_hash[y];
                    pq.push({dp[new_hash], new_hash});
                }
            }
        for (int i = 0; i < n; ++i)
            for (int j = 1; j < m; ++j) {
                int x = get_at_position(cur_hash, i * m + j - 1), y = get_at_position(cur_hash, i * m + j);
                ll new_hash =  cur_hash + (y - x) * p[i * m + j - 1] + (x - y) * p[i * m + j];
                if (dp[new_hash] == 0 || cur_cost + rev_hash[x] + rev_hash[y] < dp[new_hash]) {
                    dp[new_hash] = cur_cost + rev_hash[x] + rev_hash[y];
                    pq.push({dp[new_hash], new_hash});
                }
            }
    }
    cout << dp[trg] - 1;
    return 0;
}