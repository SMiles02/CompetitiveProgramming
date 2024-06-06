#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

void solve() {
    int n;
    cin >> n;
    int a[n + 1], c[n + 1];
    vector<int> v, do_last, to(n + 1);
    vector<bool> done(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++to[a[i]];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (to[i] == 0) {
            v.push_back(i);
        }
    }
    while (!v.empty()) {
        int x = v.back();
        v.pop_back();
        done[x] = true;
        cout << x << " ";
        if (--to[a[x]] == 0) {
            v.push_back(a[x]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!done[i]) {
            int cur = i;
            array<int, 2> mn = {c[i], i};
            done[i] = true;
            while (a[cur] != i) {
                cur = a[cur];
                done[cur] = true;
                mn = min(mn, {c[cur], cur});
            }
            cur = a[mn[1]];
            while (cur != mn[1]) {
                cout << cur << " ";
                cur = a[cur];
            }
            cout << mn[1] << " ";
        }
    }
    for (int i : do_last) {
        cout << i << " ";
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