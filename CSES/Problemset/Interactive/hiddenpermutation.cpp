#include <bits/stdc++.h>
using namespace std;

bool make_query(int x, int y) {
    cout << "? " << x << " " << y << endl;
    string s;
    cin >> s;
    return s[0] == 'Y';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> v = {0}, p(n);
    for (int i = 1; i <= n; ++i) {
        int l = 0, r = i - 1, m;
        while (l < r) {
            m = l + (r - l) / 2 + 1;
            if (make_query(v[m], i)) {
                l = m;
            }
            else {
                r = m - 1;
            }
        }
        vector<int> w;
        for (int j = 0; j <= l; ++j) {
            w.push_back(v[j]);
        }
        w.push_back(i);
        for (int j = l + 1; j < i; ++j) {
            w.push_back(v[j]);
        }
        swap(v, w);
    }
    for (int i = 1; i <= n; ++i) {
        p[v[i] - 1] = i;
    }
    cout << "! ";
    for (int i : p) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}