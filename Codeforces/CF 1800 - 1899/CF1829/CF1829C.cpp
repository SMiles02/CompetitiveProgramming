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

const int INF = 1e7;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(2, vector<int>(2, INF));
    while (n--) {
        int x;
        char a, b;
        cin >> x >> a >> b;
        v[a - '0'][b - '0'] = min(v[a - '0'][b - '0'], x);
    }
    int ans = min(v[1][0] + v[0][1], v[1][1]);
    if (ans == INF)
        ans = -1;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}