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
    int n, last_removed = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    while (last_removed < n && a[last_removed] == last_removed) {
        ++last_removed;
    }
    for (int i = 1; i <= n * 2 + 2; ++i) {
        if (i & 1) {
            cout << last_removed << endl;
        }
        else {
            cin >> last_removed;
            if (last_removed == -1) {
                break;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}