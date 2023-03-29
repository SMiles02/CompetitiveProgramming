#include <bits/stdc++.h>
using namespace std;

string gen_string(int a, int b) {
    string res;
    int ia = 0, ib = 0;
    while (ia + ib < a + b) {
        if (ia * b <= ib * a) {
            res += '0';
            ia++;
        } else {
            res += '1';
            ib++;
        }
    }
    return res;
}

void solve() {
    int a, b, x = 0, y = 0, ans = 0;
    cin >> a >> b;
    string s = gen_string(a, b), t = "";
    for (int i = 0; i < a + b; ++i) {
        if (s[i] == '0')
            ++x;
        else
            ++y;
        t += s[i];
        if (x > 0 && y > 0 && t == gen_string(x, y))
            ++ans;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}