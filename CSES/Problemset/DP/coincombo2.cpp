#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int mod=1000000007;
int ways[101][1000001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ways[0][0]=1;
    int n,x,c;
    cin>>n>>x;
    for (int cur=1;cur<=n;++cur)
    {
        cin>>c;
        for (int i=0;i<c;++i)
            ways[cur][i]=ways[cur-1][i];
        for (int j=c;j<=x;++j)
            ways[cur][j]=(ways[cur-1][j]+ways[cur][j-c])%mod;
    }
    cout<<ways[n][x];
    return 0;
}