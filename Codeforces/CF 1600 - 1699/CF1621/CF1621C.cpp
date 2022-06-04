#include <bits/stdc++.h>
using namespace std;

int query(int x) {
    int q;
    cout << "? " << x << endl;
    cin >> q;
    return q;
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i)
        if (!p[i]) {
            vector<int> v;
            v.push_back(query(i));
            v.push_back(query(i));
            while (v[0] != v.back())
                v.push_back(query(i));
            for (int i = 1; i < (int)(v).size(); ++i)
                p[v[i - 1]] = v[i];
        }
    cout << "!";
    for (int i = 1; i <= n; ++i)
        cout << " " << p[i];
    cout << endl;
}
  
int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}