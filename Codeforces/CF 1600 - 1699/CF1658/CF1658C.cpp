#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> from[N];
int to[N];

void addEdge(int x, int y) {
    from[x].push_back(y);
    ++to[y];
}

void solve() {
    int n, oC = 0, x, done = 0;
    cin >> n;
    deque<int> d;
    for (int i = 0; i < n; ++i) {
        from[i].clear();
        to[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> x;
        d.push_back(x);
        if (x == 1)
            ++oC;
    }
    if (oC != 1) {
        cout << "NO\n";
        return;
    }
    while (d.front() != 1) {
        d.push_back(d.front());
        d.pop_front();
    }
    vector<int> v = {0}, w;
    for (int i = 1; i < n; ++i) {
        x = d[i];
        if (x > v.size() + 1) {
            cout << "NO\n";
            return;
        }
        if (x <= v.size()) {
            while (x < v.size())
                v.pop_back();
            addEdge(i, v.back());
            v.pop_back();
        }
        addEdge(v.back(), i);
        v.push_back(i);
    }
    for (int i = 0; i < n; ++i)
        if (to[i] == 0)
            w.push_back(i);
    while (!w.empty()) {
        x = w.back();
        w.pop_back();
        ++done;
        for (int i : from[x])
            if (--to[i] == 0)
                w.push_back(i);
    }
    if (done == n)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}