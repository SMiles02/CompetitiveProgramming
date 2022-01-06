#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

// N = maximum number of nodes
// L = log2(N) + 2
const int N = 2e5+1, L = 19;
int up[N][L];
vector<int> e[N];

void dfs(int c, int p) {
    up[c][0] = p;
    for (int i = 1; i < L; ++i)
        up[c][i] = up[up[c][i-1]][i-1];
    for (int i : e[c])
        if (i != p)
            dfs(i, c);
}

//find the y-th ancestor of x
int lift(int x, int y) {
    for (int i = 0; i < L; ++i)
        if ((1<<i) & y)
            x = up[x][i];
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    //get nodes/edges stuff
    dfs(1,0);
    return 0;
}