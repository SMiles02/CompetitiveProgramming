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
    int n, l = 0, r = 1e9;
    cin >> n;
    set<int> s;
    while (n--) {
        int a, x;
        cin >> a >> x;
        if (a == 1) {
            l = max(l, x);
        }
        else if (a == 2) {
            r = min(r, x);
        }
        else {
            s.insert(x);
        }
    }
    if (r < l) {
        cout << "0\n";
        return;
    }
    while (!s.empty() && *s.begin() < l) {
        s.erase(s.begin());
    }
    while (!s.empty() && r < *(--s.end())) {
        s.erase(--s.end());
    }
    cout << r - l + 1 - s.size() << "\n";
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