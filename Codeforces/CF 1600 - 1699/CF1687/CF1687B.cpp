#include <bits/stdc++.h>
using namespace std;

string s;

int query() {
    cout << "? " << s << endl;
    int ret;
    cin >> ret;
    return ret;
}

int main() {
    int n, m, cur = 0, tmp;
    cin >> n >> m;
    s = string(m, '0');
    vector<int> v(m);
    vector<array<int, 2>> a(m);
    for (int i = 0; i < m; ++i) {
        s[i] = '1';
        v[i] = query();
        a[i] = {v[i], i};
        s[i] = '0';
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < m; ++i) {
        s[a[i][1]] = '1';
        tmp = query();
        if (tmp != cur + a[i][0])
            s[a[i][1]] = '0';
        else
            cur = tmp;
    }
    cout << "! " << cur << endl;
    return 0;
}