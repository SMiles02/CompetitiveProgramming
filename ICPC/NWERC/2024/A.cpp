#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string tmp;
    getline(cin, tmp);
    vector<array<string, 2>> s(n);
    for (int i = 0; i < n; ++i) {
        getline(cin, s[i][1]);
        s[i][0] = "";
        bool found = false;
        for (auto j : s[i][1]) {
            found |= ('A' <= j && j <= 'Z');
            if (found) {
                s[i][0] += j;
            }
        }
    }
    sort(s.begin(), s.end());
    for (auto i : s) {
        cout << i[1] << "\n";
    }
    return 0;
}