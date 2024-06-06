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
    vector<array<int, 2>> a(n);
    vector<bool> b(4);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
        b[0] = b[0] | (a[i][0] > 0);
        b[1] = b[1] | (a[i][0] < 0);
        b[2] = b[2] | (a[i][1] > 0);
        b[3] = b[3] | (a[i][1] < 0);
    }
    if (b[0] && b[1] && b[2] && b[3]) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}