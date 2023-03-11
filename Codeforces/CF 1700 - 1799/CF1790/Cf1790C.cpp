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
    int n, id;
    cin >> n;
    int a[n][n - 1];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n - 1; ++j)
            cin >> a[i][j];
    id = (a[1][0] != a[0][0] && a[2][0] != a[0][0]);
    cout << a[id][0] << " ";
    for (int i = 0; i < n; ++i)
        if (a[id][0] != a[i][0])
            for (int j = 0; j < n - 1; ++j)
                cout << a[i][j] << " ";
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