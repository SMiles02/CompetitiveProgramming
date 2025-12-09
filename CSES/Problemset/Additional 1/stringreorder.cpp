#include <bits/stdc++.h>
using namespace std;

string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int n = s.size(), max_freq = 0, last_char = '?';
    vector<int> f(26);
    for (auto i : s)
        ++f[i - 'A'];
    for (int i = 1; i < 26; ++i)
        if (f[i] > f[max_freq])
            max_freq = i;
    if (f[max_freq] > (n + 1) / 2) {
        cout << "-1\n";
        return 0;
    }
    while (n > 0) {
        int cur_char = 25, max_freq = 0;
        for (int i = 1; i < 26; ++i)
            if (f[i] > f[max_freq])
                max_freq = i;
        for (int i = 24; i >= 0; --i)
            if (i != last_char && f[i] > 0 && (i == max_freq || f[max_freq] <= n / 2))
                cur_char = i;
        cout << alpha[cur_char];
        --f[cur_char];
        last_char = cur_char;
        --n;
    }
    return 0;
}