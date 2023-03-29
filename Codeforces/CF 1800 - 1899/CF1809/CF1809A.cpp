// started 25 mins late exactly

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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> v(10);
    for (auto i : s)
        ++v[i - '0'];
    sort(v.rbegin(), v.rend());
    if (n == 1)
        cout << "1\n";
    else if (v[0] == n)
        cout << "-1\n";
    else if (v[0] <= (n + 1) / 2)
        cout << n << "\n";
    else
        cout << v[0] * 2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}