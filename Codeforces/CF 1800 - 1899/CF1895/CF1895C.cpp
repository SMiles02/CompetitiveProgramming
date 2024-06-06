#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void increase(map<array<int, 2>, int>& m, map<array<int, 2>, vector<int>>& mp, int x, int y, int i) {
    if (x <= 0 || y <= 0) {
        return;
    }
    // cout << x << " " << y << " " << i << " !\n";
    ++m[{x, y}];
    mp[{x, y}].push_back(i);
}

ll calc(vector<int> a, vector<int> b, vector<int> s, vector<int> l) {
    int n = a.size();
    ll ans = 0;
    map<array<int, 2>, int> m;
    map<array<int, 2>, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        int cur = b[i], curs = 0;
        for (int curl = 0; curl < l[i]; ++curl) {
            increase(m, mp, l[i] - curl * 2, s[i] - curs * 2, i);
            curs += cur % 10;
            cur /= 10;
        }
    }
    for (int i = 0; i < n; ++i) {
        ans += m[{l[i], s[i]}];
        for (int j : mp[{l[i], s[i]}]) {
            cout << i << " " << j << "\n";
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n), s(n), l(n);
    for (int i = 0, tmp; i < n; ++i) {
        cin >> a[i];
        tmp = a[i];
        while (tmp > 0) {
            b[i] *= 10;
            b[i] += tmp % 10;
            s[i] += tmp % 10;
            ++l[i];
            tmp /= 10;
        }
    }
    cout << calc(a, b, s, l);
    // + calc(b, a, s, l) - n << "\n";
    return 0;
}