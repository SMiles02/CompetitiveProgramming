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
    if (s[0] == s[n - 1]) {
        cout << s[0] << " ";
        for (int i = 1; i + 1 < n; ++i) {
            cout << s[i];
        }
        cout << " " << s[0] << "\n";
        return;
    }
    for (int i = 1; i + 1 < n; ++i) {
        if (s[i] == 'a' && s[i + 1] == 'b') {
            for (int j = 0; j < n; ++j) {
                cout << s[j];
                if (j == i - 1 || j == i) {
                    cout << " ";
                }
            }
            cout << "\n";
            return;
        }
    }
    if (s[0] == 'b') {
        cout << s[0] << " " << s[1] << " ";
        for (int i = 2; i < n; ++i) {
            cout << s[i];
        }
        cout << "\n";
    }
    else {
        cout << s[0] << " ";
        for (int i = 1; i + 1 < n; ++i) {
            cout << s[i];
        }
        cout << " " << s[n - 1] << "\n";
    }
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