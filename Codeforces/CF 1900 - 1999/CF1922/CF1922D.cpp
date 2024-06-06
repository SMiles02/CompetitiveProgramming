#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
int n, a[N], d[N], prv[N], nxt[N];
bitset<N> done;
vector<int> q, nq;

void check(int i) {
    if (1 <= i && i <= n && a[prv[i]] + a[nxt[i]] > d[i] && !done[i]) {
        nq.push_back(i);
        done[i] = 1;
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        prv[i] = i - 1;
        nxt[i] = i + 1;
        done[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }
    a[0] = a[n + 1] = 0;
    nxt[0] = 1;
    prv[n + 1] = n;
    for (int i = 1; i <= n; ++i) {
        check(i);
    }
    for (int i = 0; i < n; ++i) {
        swap(q, nq);
        cout << q.size() << " ";
        for (int i : q) {
            nxt[prv[i]] = nxt[i];
            prv[nxt[i]] = prv[i];
        }
        for (int i : q) {
            check(prv[i]);
            check(nxt[i]);
        }
        q.clear();
    }
    cout << "\n";
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