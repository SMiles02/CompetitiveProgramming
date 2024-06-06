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

const int A = 1e5 + 1;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    int a[n][m];
    vector<int> cnt1(A), cnt2(A);
    vector<ll> sum1(A), sum2(A);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            ++cnt1[a[i][j]];
            sum1[a[i][j]] += i;
            ans += 1LL * cnt1[a[i][j]] * i - sum1[a[i][j]];
        }
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            ++cnt2[a[i][j]];
            sum2[a[i][j]] += j;
            ans += 1LL * cnt2[a[i][j]] * j - sum2[a[i][j]];
        }
    }
    cout << ans << "\n";
    return 0;
}