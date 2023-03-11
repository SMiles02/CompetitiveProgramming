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
    int a, b, c, d, x, y, ans;
    cin >> a >> b >> c >> d;
    x = y = a;
    if (a == 0) {
        cout << "1\n";
        return;
    }
    if (b > c)
        swap(b, c);
    ans = a + min(b, c) * 2;
    c -= b;
    b = 0;
    if (c > a) {
        cout << ans + a + 1 << "\n";
        return;
    }
    // c <= a
    ans += c;
    a -= c;
    if (d > a)
        cout << ans + a + 1 << "\n";
    else
        cout << ans + d << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}