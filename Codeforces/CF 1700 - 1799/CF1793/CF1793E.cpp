#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e5 + 1;
vector<int> e[N];
int d[N];

string print_bool(bool b) {
    if (b)
        return "YES";
    else
        return "NO";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, x, y, z;
    cin >> n >> m;
    bool odd = false, even = false;
    while (m--) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    queue<array<int, 2>> q;
    for (int i = 1; i <= n; ++i) {
        if (d[i])
            continue;
        d[i] = 1;
        q.push({1, -1});
        while (!q.empty()) {
            x = q.front()[0];
            y = q.front()[1];
            q.pop();
            z = 1;
            for (int i : e[x]) {
                if (d[i] == 0) {
                    q.push({i, x});
                    d[i] = d[x] + 1;
                    continue;
                }
                if (i == y && --z == 0)
                    continue;
                if ((d[i] + d[x]) & 1)
                    even = true;
                else
                    odd = true;
            }
        }
    }
    cout << print_bool(odd) << "\n" << print_bool(even);
    return 0;
}