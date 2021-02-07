#include <bits/stdc++.h>
using namespace std;

const int mn = 3001;
int rk[mn][mn][2],ans;
array<int,2> pt[mn][mn];
 
array<int,2> find_set(int a, int b) {
    if (pt[a][b]=={a,b})
        return {a,b};
    return pt[a][b] = find_set(pt[a][b]);
}
 
void union_sets(int w, int x, int y, int z) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap(a, b);
        pt[b] = a;
        rk[a] += rk[b];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,a,b,c,d;
    cin>>n>>m;
    ans=n*n;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
        {
            pt[i][j]={i,j};
            rk[i][j][(i+j)&1]=1;
        }
    while (m--)
    {

    }
    cout<<ans;
    return 0;
}