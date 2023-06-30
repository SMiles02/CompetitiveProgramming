#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    set<int> t;
    for (int i = 0; i < n; ++i)
        if (s[i] == '(' ^ i % 2 == 0)
            t.insert(i + 1);
    while (q--) {
        int i;
        cin >> i;
        if (t.count(i))
            t.erase(i);
        else
            t.insert(i);
        if (n % 2 == 0 && (t.empty() || (*t.begin() % 2 == 0 && *(--t.end()) % 2 == 1)))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}