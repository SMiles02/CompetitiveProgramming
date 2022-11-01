#include <bits/stdc++.h>
using namespace std;

const int INF = -1e9-5;

void solve() {
    int n, cur = 0, l, r, x;
    cin >> n;
    vector<int> ans(n, 1e9), most_dist(n + 1, INF);
    set<int> times, held, colours_held;
    set<array<int, 3>> past;
    map<int, int> cnt;
    map<int, vector<array<int, 2>>> in, out;
    set<array<int, 2>, greater<array<int, 2>>> prev;
    prev.insert({INF, n + 1});
    prev.insert({INF, n + 2});
    for (int i = 0; i < n; ++i) {
        cin >> l >> r >> x;
        times.insert(l);
        times.insert(r);
        in[l].push_back({x, i});
        out[r].push_back({x, i});
    }
    for (int i : times) {
        for (auto j : in[i]) {
            if (++cnt[j[0]] == 1) {
                ++cur;
                colours_held.insert(j[0]);
            }
            if ((*prev.begin())[1] != j[0])
                ans[j[1]] = min(ans[j[1]], i - (*prev.begin())[0]);
            else
                ans[j[1]] = min(ans[j[1]], i - (*++prev.begin())[0]);
            held.insert(j[1]);
        }
        if (cur > 1) {
            for (auto j : past)
                ans[j[1]] = min(ans[j[1]], i - j[2]);
            for (int j : held)
                ans[j] = 0;
            past.clear();
            held.clear();
        }
        else if (cur == 1) {
            x = *colours_held.begin();
            while (!past.empty() && (*past.begin())[0] != x) {
                ans[(*past.begin())[1]] = min(ans[(*past.begin())[1]], i - (*past.begin())[2]);
                past.erase(past.begin());
            }
            while (!past.empty() && (*--past.end())[0] != x) {
                ans[(*--past.end())[1]] = min(ans[(*--past.end())[1]], i - (*--past.end())[2]);
                past.erase(--past.end());
            }
        }
        for (auto j : out[i]) {
            if (--cnt[j[0]] == 0) {
                --cur;
                colours_held.erase(j[0]);
            }
            if (held.count(j[1])) {
                held.erase(j[1]);
                past.insert({j[0], j[1], i});
            }
            if (prev.count({most_dist[j[0]], j[0]}))
                prev.erase({most_dist[j[0]], j[0]});
            most_dist[j[0]] = i;
            prev.insert({most_dist[j[0]], j[0]});
        }
        while (prev.size() > 2)
            prev.erase(--prev.end());
    }
    for (int i : ans)
        cout << i << " ";
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}