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
    vector<int> a(n), ans;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int iter = 0; iter < 1000; ++iter) {
        for (int i = 1; i < n; ++i) {
            a[i] = max(a[i] - a[i - 1], 0);
        }
        a[0] = max(a[0] - a[n - 1], 0);
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0 && a[(i + n - 1) % n] == 0) {
            ans.push_back(i + 1);
        }
    }
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
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