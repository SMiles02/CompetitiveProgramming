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
    int n, ans = 0, cnt = 0;
    cin >> n;
    vector<int> v;
    while (n--) {
        int k;
        cin >> k;
        for (int i = 2; i * i <= k; ++i)
            while (k % i == 0) {
                v.push_back(i);
                k /= i;
            }
        if (k > 1)
            v.push_back(k);
    }
    sort(v.begin(), v.end());
    while (v.size() > 1) {
        if (v[v.size() - 1] == v[v.size() - 2]) {
            ++ans;
            v.pop_back();
            v.pop_back();
        }
        else {
            ++cnt;
            v.pop_back();
        }
    }
    cout << ans + (cnt + v.size()) / 3 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}