#include <bits/stdc++.h>
using namespace std;

string alpha = "abcdefghijklmnopqrstuvwxyz";

void solve() {
    string a, s = "", t = "", u = "";
    cin >> a;
    bool flag = false;
    vector<int> f(26);
    for (auto i : a)
        ++f[i - 'a'];
    for (int i = 0; i < 26; ++i) {
        if (flag)
            while (f[i] > 0) {
                s += alpha[i];
                --f[i];
            }
        while (f[i] > 1) {
            s += alpha[i];
            t += alpha[i];
            f[i] -= 2;
        }
        if (f[i]) {
            int cnt = 0;
            for (int j = i + 1; j < 26; ++j)
                cnt += f[j] > 0;
            if (cnt == 1)
                u += alpha[i];
            else if (cnt > 1) {
                t += alpha[i];
                flag = true;
            }
            else
                s += alpha[i];
        }
    }
    reverse(t.begin(), t.end());
    cout << s << u << t << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}