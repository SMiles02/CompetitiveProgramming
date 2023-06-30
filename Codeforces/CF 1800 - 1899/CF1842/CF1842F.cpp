#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
vector<int> e[N];
int n, d[N], p[N], cur_ans, sub[N], tot_black;
bitset<N> black;
 
void dfs(int c, int par, int dt) {
    d[c] = dt;
    p[c] = par;
    for (int i : e[c])
        if (i != par)
            dfs(i, c, dt + 1);
}
 
int find_max() {
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (d[i] >= d[ans])
            ans = i;
    return ans;
}

void calc_ans(int c, int par) {
    sub[c] = black[c];
    for (int i : e[c])
        if (i != par) {
            calc_ans(i, c);
            cur_ans += abs(tot_black - sub[i] * 2);
            sub[c] += sub[i];
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x, y;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, 0, 0);
    dfs(x = find_max(), 0, 0);
    y = find_max();
    cout << "0 ";
    vector<int> v;
    for (int i = 1; i <= n; ++i) {
        if (y != 0) {
            black[y] = 1;
            v.push_back(y);
            ++tot_black;
            y = p[y];
        }
        else {
            int done = 0;
            while (done == 0) {
                for (int j : e[v.back()])
                    if (!black[j]) {
                        black[j] = 1;
                        v.push_back(j);
                        ++tot_black;
                        done = j;
                        break;
                    }
                if (done == 0)
                    v.pop_back();
            }
            v.push_back(done);
        }
        cur_ans = 0;
        calc_ans(1, 0);
        cout << cur_ans << " ";
    }
    return 0;
}