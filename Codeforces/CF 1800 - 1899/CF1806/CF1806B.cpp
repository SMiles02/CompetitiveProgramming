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
    int n, k;
    cin >> n;
    vector<int> cnt(2);
    for (int i = 0; i < n; ++i) {
        cin >> k;
        if (k < 2)
            ++cnt[k];
    }
    if (cnt[0] <= (n + 1) / 2)
        cout << "0\n";
    else if (cnt[1] > 0 && cnt[0] + cnt[1] == n)
        cout << "2\n";
    else
        cout << "1\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}