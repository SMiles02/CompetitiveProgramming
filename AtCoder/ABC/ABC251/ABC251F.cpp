#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5 + 1;
vector<int> e[N];
bitset<N> done;

void dfs(int c) {
    done[c] = 1;
    for (int i : e[c])
        if (!done[i]) {
            cout << c << " " << i << "\n";
            dfs(i);
        }
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, x, y;
    cin >> n >> m;
    while (m--) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1);
    done.reset();
    queue<int> q;
    q.push(1);
    done[1] = 1;
    while (!q.empty()) {
        x = q.front();
        q.pop();
        for (int i : e[x])
            if (!done[i]) {
                done[i] = 1;
                cout << x << " " << i << "\n";
                q.push(i);
            }
    }
    return 0;
}