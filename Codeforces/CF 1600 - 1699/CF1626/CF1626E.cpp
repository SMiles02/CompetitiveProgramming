#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1;
int b[N], sub[N];
bitset<N> dpUp, dpDown;
vector<int> e[N];

void dfsSub(int c, int p) {
    if (b[c])
        sub[c] = 1;
    for (int i : e[c])
        if (i != p) {
            dfsSub(i, c);
            sub[c] += sub[i];
        }
}

void dfsD(int c, int p) {
    if (b[c])
        dpDown[c] = 1;
    for (int i : e[c])
        if (i != p) {
            dfsD(i, c);
            if (b[i] || (dpDown[i] && sub[i] > 1))
                dpDown[c] = 1;
        }
}

void dfsU(int c, int p) {
    if (b[c] || b[p] || ((dpUp[p] || dpDown[p]) && sub[1] - sub[c] > 1))
        dpUp[c] = 1;
    for (int i : e[c])
        if (i != p)
            dfsU(i, c);
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x, y;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfsSub(1, 0);
    dfsD(1, 0);
    dfsU(1, 0);
    for (int i = 1; i <= n; ++i)
        cout << (dpDown[i] | dpUp[i]) << " ";
    return 0;
}