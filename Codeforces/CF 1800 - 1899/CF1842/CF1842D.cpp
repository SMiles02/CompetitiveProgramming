#include <bits/stdc++.h>
using namespace std;

struct disjoint_set_union {
    vector<int> p, sz;
    disjoint_set_union(int n) : p(n + 1), sz(n + 1, 1) {
        iota(p.begin(), p.end(), 0);
    }
    int find_set(int i) {
        return i == p[i] ? i : p[i] = find_set(p[i]);
    }
    void unite(int i, int j) {
        i = find_set(i);
        j = find_set(j);
        if (i != j) {
            if (sz[i] < sz[j])
                swap(i, j);
            p[j] = i;
            sz[i] += sz[j];
        }
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> a(m);
    disjoint_set_union dsu(n);
    vector<long long> max_time(n + 1, 1e18), play_time(n * n);
    vector<string> plays(n * n, string(n, '0'));
    for (auto &cond : a) {
        for (int i = 0; i < 3; ++i)
            cin >> cond[i];
        dsu.unite(cond[0], cond[1]);
    }
    if (!dsu.connected(1, n)) {
        cout << "inf\n";
        return 0;
    }
    max_time[n] = 0;
    for (int _ = 0; _ < n; ++_) {
        for (auto cond : a) {
            max_time[cond[0]] = min(max_time[cond[0]], max_time[cond[1]] + cond[2]);
            max_time[cond[1]] = min(max_time[cond[1]], max_time[cond[0]] + cond[2]);
        }
    }
    long long tot_play_time = 0;
    for (int i = 0; i < n * n; ++i) {
        long long cur_play_time = max_time[1];
        plays[i][0] = '1';
        for (int j = 2; j < n; ++j) {
            if (max_time[j] > 0) {
                plays[i][j - 1] = '1';
                cur_play_time = min(cur_play_time, max_time[j]);
            }
        }
        for (int j = 1; j < n; ++j) {
            if (plays[i][j - 1] == '1') {
                max_time[j] -= cur_play_time;
            }
        }
        tot_play_time += cur_play_time;
        play_time[i] = cur_play_time;
    }
    cout << tot_play_time << " " << n * n << "\n";
    for (int i = 0; i < n * n; ++i) {
        cout << plays[i] << " " << play_time[i] << "\n";
    }
    return 0;
}