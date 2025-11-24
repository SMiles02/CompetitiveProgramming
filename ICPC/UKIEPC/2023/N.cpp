#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

string alpha = "abcdefghijklmnopqrstuvwxyz";

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, cur = 0;
    cin >> n;
    vector<pair<string, int>> s(n);
    vector<string> ans(n, "");
    for (int i = 0; i < n; ++i) {
        string a = "", b = "";
        bool passed = false;
        while (true) {
            char c;
            cin >> c;
            if (c == 'L') {
                break;
            }
            else if (c == '.') {
                passed = true;
            }
            else if (passed) {
                b += c;
            }
            else {
                a += c;
            }
        }
        while (sz(a) < 6) {
            a = "0" + a;
        }
        while (sz(b) < 12) {
            b += "0";
        }
        // cout << a << b << "\n";
        s[i].first = a + b;
        s[i].second = i;
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < n; ++i) {
        if (i != 0 && s[i].first != s[i - 1].first) {
            ++cur;
        }
        ans[s[i].second] += alpha[cur % 26];
        ans[s[i].second] += alpha[(cur / 26) % 26];
        ans[s[i].second] += alpha[(cur / (26 * 26)) % 26];
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << "\n";
    }
    return 0;
}