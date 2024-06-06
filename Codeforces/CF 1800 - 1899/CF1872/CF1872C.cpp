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
    int l, r;
    cin >> l >> r;
    if (r < 4) {
        cout << "-1\n";
    }
    else if (r % 2 == 0 || l < r) {
        cout << r / 2 << " " << r / 2 << "\n";
    }
    else {
        for (int i = 3; i * i <= r; i += 2) {
            if (r % i == 0) {
                cout << i << " " << r - i << "\n";
                return;
            }
        }
        cout << "-1\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}