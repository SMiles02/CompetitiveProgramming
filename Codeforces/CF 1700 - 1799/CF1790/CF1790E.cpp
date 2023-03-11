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
    int n, a = 0, b = 0;
    bool found_first = false;
    cin >> n;
    for (int i = 29; i >= 0; --i)
        if ((1 << i) & n) {
            if (b == 0)
                b += (1 << i);
            else
                a += (1 << i);
        }
    for (int i = 29; i >= 0; --i) {
        if ((1 << i) & n)
            found_first = true;
        else if (found_first) {
            if (a + b + (1 << (i + 1)) <= n * 2) {
                a += (1 << i);
                b += (1 << i);
            }
        }
    }
    if (a + b == n * 2 && a + b == (a ^ b) * 2)
        cout << a << " " << b << "\n";
    else
        cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}