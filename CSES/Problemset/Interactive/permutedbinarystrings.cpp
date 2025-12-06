#include <bits/stdc++.h>
using namespace std;

int n;

string make_query(int p) {
    cout << "? ";
    for (int i = 1; i <= n; ++i) {
        cout << min(i & (1 << p), 1);
    }
    cout << endl;
    string s;
    cin >> s;
    return s;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<int> ans(n);
    for (int i = 0; i < 10; ++i) {
        string s = make_query(i);
        for (int j = 0; j < n; ++j) {
            if (s[j] == '1') {
                ans[j] += 1 << i;
            }
        }
    }
    cout << "!";
    for (int i : ans) {
        cout << " " << i;
    }
    cout << endl;
    return 0;
}