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
    if (n == 3) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if (n % 2 == 0) {
        for (int i = 0; i < n; ++i) {
            if (i & 1)
                cout << "-1 ";
            else
                cout << "1 ";
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            if (i & 1)
                cout << -(n / 2) << " ";
            else
                cout << (n / 2) - 1 << " ";
        }
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