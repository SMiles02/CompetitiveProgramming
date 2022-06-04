#include <bits/stdc++.h>
using namespace std;

const int N = 26;
bitset<N> two[N], three[N][N];

void solve() {
    int n;
    cin >> n;
    bool ans = 0;
    string s;
    for (int i = 0; i < 26; ++i) {
        two[i].reset();
        for (int j = 0; j < 26; ++j)
            three[i][j].reset();
    }

    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s.size() == 1)
            ans = 1;
        else if (s.size() == 2) {
            if (s[0] == s[1] || two[s[1] - 'a'][s[0] - 'a'])
                ans = 1;
            for (int i = 0; i < 26; ++i)
                if (three[s[1] - 'a'][s[0] - 'a'][i])
                    ans = 1;
            two[s[0] - 'a'][s[1] - 'a'] = 1;
        }
        else {
            if (s[0] == s[2] || three[s[2] - 'a'][s[1] - 'a'][s[0] - 'a'] || two[s[2] - 'a'][s[1] - 'a'])
                ans = 1;
            three[s[0] - 'a'][s[1] - 'a'][s[2] - 'a'] = 1;
        }
    }
    if (ans)
        cout << "YES\n";
    else
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