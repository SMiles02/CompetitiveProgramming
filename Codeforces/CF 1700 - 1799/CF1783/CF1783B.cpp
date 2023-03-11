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
    int n, l = 1, r;
    cin >> n;
    r = n * n;
    if (n & 1) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i + j) & 1)
                    cout << r-- << " ";
                else
                    cout << l++ << " ";
            }
            cout << "\n";
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            vector<int> v;
            for (int j = 0; j < n; ++j) {
                if (j & 1)
                    v.push_back(r--);
                else
                    v.push_back(l++);
            }
            if (i & 1)
                reverse(v.begin(), v.end());
            for (int j : v)
                cout << j << " ";
            cout << "\n";
        }
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