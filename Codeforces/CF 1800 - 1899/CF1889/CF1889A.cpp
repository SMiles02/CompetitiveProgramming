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
    vector<int> cnt(2), ans;
    for (auto i : s) {
        ++cnt[i - '0'];
    }
    if (cnt[0] != cnt[1]) {
        cout << "-1\n";
        return;
    }
    bool ok = false;
    while (!ok) {
        ok = true;
        n = s.size();
        for (int i = 0; i < n && ok; ++i) {
            if (s[i] == s[n - i - 1]) {
                string t = "";
                if (s[i] == '0') {
                    for (int j = 0; j <= n - i - 1; ++j) {
                        t += s[j];
                    }
                    ans.push_back(t.size());
                    t += "01";
                    for (int j = n - i; j < n; ++j) {
                        t += s[j];
                    }
                }
                else {
                    for (int j = 0; j < i; ++j) {
                        t += s[j];
                    }
                    ans.push_back(t.size());
                    t += "01";
                    for (int j = i; j < n; ++j) {
                        t += s[j];
                    }
                }
                swap(s, t);
                // cout << s << " " << t << "\n";
                ok = false;
            }
        }
        // cout << s << endl;
    }
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
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