#include <bits/stdc++.h>
using namespace std;

// post-contest notes:
// - store the cells occupied by black and white stones in a set
// - for each stone of the colour that moves next, check all 8 5-stone 'lines' it's part of
// specifically, check there are 4 stones of that colour there, and that the last position is unoccupied

int do_count(set<array<int, 2>>& s, array<int, 2>& a, array<int, 2>& b, array<int, 2>& c, array<int, 2>& d, array<int, 2>& e) {
    return s.count(a) + s.count(b) + s.count(c) + s.count(d) + s.count(e);
}

array<int, 2> add(array<int, 2> a, array<int, 2> b) {
    return {a[0] + b[0], a[1] + b[1]};
}

set<array<int, 2>> s[2], o;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<array<int, 2>> dir;
    int n;
    cin >> n;
    for (int i = -1; i < 2; ++i)
        for (int j = -1; j < 2; ++j)
                if (i != 0 || j != 0)
                    dir.push_back({i, j});
    for (int i = 0; i < n; ++i) {
        int x, y;
        char c;
        cin >> c >> x >> y;
        s[c == 'W'].insert({x, y});
        o.insert({x, y});
    }
    if (n & 1)
        swap(s[0], s[1]);
    for (auto i : s[0])
        for (auto j : dir) {
            array<int, 2> a, b, c, d, e;
            a = i;
            b = add(a, j);
            c = add(b, j);
            d = add(c, j);
            e = add(d, j);
            if (do_count(s[0], a, b, c, d, e) == 4 && do_count(o, a, b, c, d, e) != 5) {
                vector<array<int, 2>> v = {a, b, c, d, e};
                while (o.count(v.back())) {
                    o.erase(v.back());
                    v.pop_back();
                }
                cout << v.back()[0] << " " << v.back()[1] << "\n";
                return 0;
            }
        }
    cout << "0\n";
    return 0;
}