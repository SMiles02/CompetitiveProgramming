#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

bool is_large(ll n) {
    if (n <= 0) {
        return false;
    }
    while (n > 0) {
        if (n % 10 < 5) {
            return false;
        }
        n /= 10;
    }
    return true;
}

void solve() {
    string s;
    cin >> s;
    bool ok = s[0] == '1' && s.back() != '9';
    for (int i = 1; i + 1 < s.size(); ++i) {
        if (s[i] == '0') {
            ok = false;
        }
    }
    if (ok) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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