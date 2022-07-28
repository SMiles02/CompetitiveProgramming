#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
string s;

int score() {
    char c = '?';
    int cur = 0;
    vector<int> v(k);
    for (auto i : s) {
        if (i == c)
            ++cur;
        else {
            c = i;
            cur = 1;
        }
        v[c - 'a'] = max(v[c - 'a'], cur);
    }
    cur = n;
    for (int i = 0; i < k; ++i)
        cur = min(cur, v[i]);
    return cur;
}

void rec(int i) {
    if (i == n) {
        ans = max(ans, score());
        return;
    }
    if (s[i] == '?') {
        for (int j = 0; j < k; ++j) {
            s[i] = 'a' + j;
            rec(i + 1);
        }
        s[i] = '?';
    }
    else
        rec(i + 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    cin >> s;
    rec(0);
    cout << ans;
    return 0;
}