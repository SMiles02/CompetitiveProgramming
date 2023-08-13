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
    string s[3];
    for (int i = 0; i < 3; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = i + 1; j < 9; ++j) {
            for (int k = j + 1; k < 9; ++k) {
                if (s[i / 3][i % 3] == s[j / 3][j % 3] && s[i / 3][i % 3] == s[k / 3][k % 3] && s[i / 3][i % 3] != '.' && i / 3 - j / 3 == j / 3 - k / 3 && (i % 3) - (j % 3) == (j % 3) - (k % 3)) {
                    cout << s[i / 3][i % 3] << "\n";
                    return;
                }
            }
        }
    }
    cout << "DRAW\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}