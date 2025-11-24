#include <bits/stdc++.h>
using namespace std;

void increment(char& c) {
    ++c;
    if (c == 'E') {
        c = 'A';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < m; ++j) {
            increment(s[i][j]);
            if ((i > 0 && s[i][j] == s[i - 1][j]) || (j > 0 && s[i][j] == s[i][j - 1])) {
                increment(s[i][j]);
            }
            if ((i > 0 && s[i][j] == s[i - 1][j]) || (j > 0 && s[i][j] == s[i][j - 1])) {
                increment(s[i][j]);
            }
        }
        cout << s[i] << "\n";
    }
    return 0;
}