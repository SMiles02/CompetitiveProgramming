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
    int n, x = 0, y = 0;
    cin >> n;
    string s;
    cin >> s;
    for (auto i : s) {
        if (i == 'N') {
            ++y;
        }
        else if (i == 'S') {
            --y;
        }
        else if (i == 'E') {
            ++x;
        }
        else {
            --x;
        }
    }
    if (x % 2 != 0 || y % 2 != 0) {
        cout << "NO\n";
        return;
    }
    if (x != 0 || y != 0) {
        int a = 0, b = 0;
        for (auto i : s) {
            if (i == 'N' || i == 'S') {
                if (b == y / 2) {
                    cout << "H";
                }
                else {
                    cout << "R";
                    if (i == 'N') {
                        ++b;
                    }
                    else {
                        --b;
                    }
                }
            }
            else {
                if (a == x / 2) {
                    cout << "H";
                }
                else {
                    cout << "R";
                    if (i == 'E') {
                        ++a;
                    }
                    else {
                        --a;
                    }
                }
            }
        }
        cout << "\n";
        return;
    }
    if (n == 2) {
        cout << "NO\n";
        return;
    }
    string ans = string(n, 'R');
    ans[0] = 'H';
    for (int i = 1; i < n; ++i) {
        if ((s[0] == 'N' && s[i] == 'S') || (s[0] == 'S' && s[i] == 'N') || (s[0] == 'E' && s[i] == 'W') || (s[0] == 'W' && s[i] == 'E')) {
            ans[i] = 'H';
            break;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}