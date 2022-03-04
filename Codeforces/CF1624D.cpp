#include <bits/stdc++.h>
using namespace std;

int k;

bool checkEven(int x, vector<int> v) {
    for (int i = 0; i < k; ++i) {
        int g = 0;
        for (int j = 0; j < 26; ++j)
            while (v[j] > 1 && g < x) {
                v[j] -= 2;
                g += 2;
            }
        if (g < x)
            return 0;
    }
    return 1;
}

bool checkOdd(int x, vector<int> v) {
    int c = 0;
    for (int i = 0; i < 26; ++i)
        if (v[i] & 1) {
            --v[i];
            ++c;
        }
    for (int i = 0; i < 26; ++i)
        while (v[i] > 0 && c < k) {
            --v[i];
            ++c;
        }
    if (c < k)
        return 0;
    return checkEven(x - 1, v);
}

void solve() {
    int n, l, r, m;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> v(26);
    for (auto i : s)
        ++v[i - 'a'];
    l = 0;
    r = n / 2;
    while (l < r) {
        m = l + (r - l) / 2 + 1;
        if (checkEven(m * 2, v))
            l = m;
        else
            r = m - 1;
    }
    cout << l * 2 + checkOdd(l * 2 + 1, v) << "\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}