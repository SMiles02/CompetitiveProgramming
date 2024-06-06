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

const int N = 2'700'000;
int dp[N];

void solve() {
    int n;
    cin >> n;
    cout << (n / N) * (N / 15) + dp[n % N] << "\n";
}

void dp_help(int i, int x) {
    if (i >= x) {
        dp[i] = min(dp[i], dp[i - x] + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 1; i < N; ++i) {
        dp[i] = dp[i - 1] + 1;
        dp_help(i, 3);
        dp_help(i, 6);
        dp_help(i, 10);
        dp_help(i, 15);
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}