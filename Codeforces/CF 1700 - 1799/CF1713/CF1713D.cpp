#include <bits/stdc++.h>
using namespace std;

int query(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int ret;
    cin >> ret;
    return ret;
}

void solve() {
    int n, q;
    cin >> n;
    vector<int> v(1 << n);
    iota(v.begin(), v.end(), 1);
    while (v.size() > 2) {
        vector<int> w;
        for (int i = 0; i < v.size(); i += 4) {
            q = query(v[i], v[i + 2]);
            if (q == 1) {
                w.push_back(v[i]);
                w.push_back(v[i + 3]);
            }
            else if (q == 2) {
                w.push_back(v[i + 2]);
                w.push_back(v[i + 1]);
            }
            else {
                w.push_back(v[i + 1]);
                w.push_back(v[i + 3]);
            }
        }
        swap(v, w);
    }
    if (v.size() == 2) {
        q = query(v[0], v[1]);
        if (q == 2)
            swap(v[0], v[1]);
    }
    cout << "! " << v[0] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}