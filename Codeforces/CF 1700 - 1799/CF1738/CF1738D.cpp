#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int a[N], b[N], n, x, y;

bool check(int k, vector<int> v) {
    x = n + 1;
    y = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] <= k) {
            a[v[i]] = x;
            y = v[i];
        }
        else {
            a[v[i]] = y;
            x = v[i];
        }
    } 
    for (int i = 1; i <= n; ++i)
        cerr << a[i] << " ";
    cerr <<"\n"; 
    for (int i = 1; i <= n; ++i)
        if (a[i] != b[i + 1])
            return false;
    return true;
}

int to[N];
vector<int> from[N];
bitset<N> blank;

void solve() {
    int l, r;
    cin >> n;
    vector<int> small, big;
    for (int i = 1; i <= n; ++i) {
        to[i] = 0;
        from[i].clear();
        blank[i] = 0;
    }
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    l = 1;
    r = n;
    // k = n => all b_i = n + 1
    // k = 1 => 
    for (int i = 1; i <= n; ++i) {
        if (b[i] == n + 1) {
            l = i;
            blank[i] = 1;
        }
        else if (b[i] == 0) {
            r = min(r, i - 1);
            blank[i] = 1;
        }
        else if (i != b[i]) {
            l = max(l, min(i, b[i]));
            r = min(r, max(i, b[i]) - 1);
            from[b[i]].push_back(i);
            ++to[i];
        }
        // cout << l << " " << r << "\n";
    }
    // cout << l << " " << r << "\n";
    // if (l != r) {
    //     cerr << "kms\n";
    // }
    cout << l << "\n";
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    for (int i = 1; i <= n; ++i) {
        if (to[i] == 0) {
            // cerr << i << " " << (int)from[i].size() << "\n";
            pq.push({(int)from[i].size(), i});
        }
    }
    vector<int> v;
    while (!pq.empty()) {
        x = pq.top()[1];
        pq.pop();
        v.push_back(x);
        for (int i : from[x])
            if (--to[i] == 0)
                pq.push({(int)from[i].size(), i});
    }
    cerr << check(l, v) << "\n";
    for (int i : v)
        cout << i << " ";
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