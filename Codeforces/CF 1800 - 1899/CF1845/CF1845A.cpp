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
    int n, k, x;
    cin >> n >> k >> x;
    if (x != 1) {
        cout << "YES\n" << n << "\n";
        for (int i = 0; i < n; ++i)
            cout << "1 ";
        cout << "\n";
        return;
    }
    if (k == 1 || n == 1) {
        cout << "NO\n";
        return;
    }
    if (k == 2) {
        if (n & 1) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n" << " " << n / 2 << "\n";
        for (int i = 0; i < n / 2; ++i)
            cout << "2 ";
        cout << "\n";
        return;
    }
    // k >= 3, x = 1
    vector<int> v;
    if (n & 1) {
        v.push_back(3);
        n -= 3;
    }
    while (n > 0) {
        v.push_back(2);
        n -= 2;
    }
    cout << "YES\n" << v.size() << "\n";
    for (int i : v) {
        cout << i << " ";
    }
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