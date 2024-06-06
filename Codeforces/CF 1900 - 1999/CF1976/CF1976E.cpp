#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, ans = 1;
    cin >> n >> q;
    vector<int> l(q), r(q), v = {n + 2}, p(n + 2);
    for (int i = 0; i < q; ++i) {
        cin >> l[i];
    }
    for (int i = 0; i < q; ++i) {
        cin >> r[i];
    }
    vector<int> head(n + 3), tail(n + 3);
    head[n] = n + 1;
    tail[n + 1] = n;
    tail[n] = n + 2;
    head[n + 2] = n;
    for (int i = 0; i < q; ++i) {
        if (l[i] < r[i]) {
            head[tail[r[i]]] = l[i];
            tail[l[i]] = tail[r[i]];
        }
        else {
            tail[head[l[i]]] = r[i];
            head[r[i]] = head[l[i]];
        }
        head[l[i]] = r[i];
        tail[r[i]] = l[i];
    }
    while (v.back() != n + 1) {
        v.push_back(head[v.back()]);
    }
    for (int i = 1; i < v.size(); ++i) {
        if (max(v[i - 1], v[i]) <= n) {
            ++p[max(v[i - 1], v[i])];
        }
        else {
            ++p[min(v[i - 1], v[i])];
        }
    }
    for (int i = n; i >= 1; --i) {
        p[i] += p[i + 1];
        if (head[i] == 0) {
            ans = (1LL * ans * p[i]++) % 998244353;
        }
    }
    cout << ans << "\n";
    return 0;
}