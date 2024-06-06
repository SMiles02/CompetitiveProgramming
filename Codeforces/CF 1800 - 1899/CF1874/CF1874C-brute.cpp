#include <bits/stdc++.h>
using namespace std;

const int N = 12;
double dp[N + 1];

void rec(deque<int> v, double pb) {
    if (v.empty()) {
        return;
    }
    if (v.size() == 1) {
        dp[v[0]] += pb;
        return;
    }
    int sz = v.size();
    dp[v[0]] += pb / sz;
    v.pop_front();
    for (int i : v) {
        deque<int> w;
        for (int j : v) {
            if (i != j) {
                w.push_back(j);
            }
        }
        rec(w, pb / sz);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    deque<int> v(N);
    iota(v.begin(), v.end(), 1);
    rec(v, 1);
    for (int i = 1; i <= N; ++i) {
        cout << i << ": ";
        cout << fixed << setprecision(15) << dp[i] << "\n";
    }
    return 0;
}