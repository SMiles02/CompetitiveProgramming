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
    string s;
    cin >> s;
    int score;
    bool ok1 = true, ok2 = true;
    score = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(')
            ++score;
        else
            --score;
        ok1 &= score >= 0;
    }
    score = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '(')
            ++score;
        else
            --score;
        ok2 &= score >= 0;
    }
    if (score != 0) {
        cout << "-1\n";
        return;
    }
    if (ok1 || ok2) {
        cout << "1\n";
        for (int i = 0; i < n; ++i)
            cout << "1 ";
        cout << "\n";
        return;
    }
    int pos = 0, neg = 0;
    cout << "2\n";
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            if (neg) {
                --neg;
                cout << "2 ";
            }
            else {
                ++pos;
                cout << "1 ";
            }
        }
        else {
            if (pos) {
                --pos;
                cout << "1 ";
            }
            else {
                ++neg;
                cout << "2 ";
            }
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