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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, l, r, m;
    cin >> n;
    int a[n + 1];
    vector<int> dp(n + 1), v = {0};
    vector<ll> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
        if (p[i] < p[v.back()])
            v.push_back(i);
        else {
            l = 0;
            r = v.size() - 1;
            while (l < r) {
                m = l + (r - l) / 2;
                if (p[i] < p[v[m]])
                    l = m + 1;
                else
                    r = m;
            }
            dp[i] = i - v[l] + dp[l];
        }
        dp[i] = max(dp[i], dp[i - 1]);
    }
    cout << dp[n] << "\n";
    return 0;
}