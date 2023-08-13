#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q, cnt = 0;
    cin >> n;
    vector<array<int, 4>> p(n);
    map<int, int> hash, reverse_hash;
    set<int> s;
    for (auto &i : p) {
        for (auto &j : i) {
            cin >> j;
            s.insert(j);
        }
    }
    cin >> q;
    vector<int> qa(q), ans(q);
    for (int i = 0; i < q; ++i) {
        cin >> qa[i];
        s.insert(qa[i]);
    }
    for (int i : s) {
        hash[i] = cnt;
        reverse_hash[cnt] = i;
        ++cnt;
    }
    priority_queue<int> active_b;
    vector<vector<int>> start_here(cnt), end_here(cnt), queries(cnt);
    vector<int> ans_at_point(cnt), active_b_cnt(cnt);
    for (auto &i : p) {
        start_here[hash[i[1]]].push_back(hash[i[3]]);
        end_here[hash[i[0]]].push_back(hash[i[3]]);
    }
    for (int i = 0; i < q; ++i) {
        queries[hash[qa[i]]].push_back(i);
    }
    for (int i = cnt - 1; i >= 0; --i) {
        for (int j : start_here[i]) {
            active_b.push(j);
            ++active_b_cnt[j];
        }
        ans_at_point[i] = i;
        while (!active_b.empty() && active_b_cnt[active_b.top()] == 0) {
            active_b.pop();
        }
        if (!active_b.empty()) {
            ans_at_point[i] = max(ans_at_point[i], ans_at_point[active_b.top()]);
        }
        for (int j : queries[i]) {
            ans[j] = ans_at_point[i];
        }
        for (int j : end_here[i]) {
            --active_b_cnt[j];
        }
    }
    for (int i : ans) {
        cout << reverse_hash[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}