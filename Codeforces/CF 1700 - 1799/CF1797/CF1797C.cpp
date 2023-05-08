#include <bits/stdc++.h>
using namespace std;

int dist(int a, int b, int c, int d) {
    return max(abs(a - c), abs(b - d));
}

bool local = false;
int pos1, pos2;

int make_query(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int ret;
    if (local)
        ret = dist(x, y, pos1, pos2);
    else
        cin >> ret;
    return ret;
}

void print_ans(int x, int y) {
    cout << "! " << x << " " << y << endl;
}

void solve() {
    int n, m, a, b, c;
    cin >> n >> m;
    if (local)
        cin >> pos1 >> pos2;
    a = make_query(1, 1);
    b = make_query(n, m);
    if (a + 1 == n - b) {
        c = make_query(a + 1, 1);
        print_ans(a + 1, c + 1);
    }
    else if (a + 1 == m - b) {
        c = make_query(1, a + 1);
        print_ans(c + 1, a + 1);
    }
    else {
        vector<int> x = {a + 1, n - b};
        vector<int> y = {a + 1, m - b};
        vector<array<int, 2>> v;
        for (auto i : x)
            for (auto j : y)
                if (dist(i, j, 1, 1) == a && dist(i, j, n, m) == b && 1 <= i && i <= n && 1 <= j && j <= m)
                    v.push_back({i, j});
        c = make_query(v[0][0], v[0][1]);
        print_ans(v[c != 0][0], v[c != 0][1]);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}