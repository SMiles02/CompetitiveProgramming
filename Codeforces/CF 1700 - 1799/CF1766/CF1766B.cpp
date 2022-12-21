#include <bits/stdc++.h>
using namespace std;

const int N = 26;
int b[N][N];

void solve() {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            b[i][j] = 0;
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i < n; ++i) {
        if (b[s[i - 1] - 'a'][s[i] - 'a'] && !(b[s[i - 1] - 'a'][s[i] - 'a'] == 1 && s[i] == s[i - 1] && i - 2 >= 0 && s[i] == s[i - 2])) {
            cout << "YES\n";
            return;
        }
        ++b[s[i - 1] - 'a'][s[i] - 'a'];
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}