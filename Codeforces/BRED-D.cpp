#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

bool c[5001][5001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,t,a,b,ans=0;
    cin>>n>>m;
    cin>>t;
    while (t--)
    {
        cin>>a>>b;
        c[a][b]=1;
    }
    for (int i=5000;i;--i)
        for (int j=5000;j;--j)
            if (c[i][j])
            {
                ++ans;
                c[i-1][j]=1;
                c[i][j-1]=1;
            }
    cout<<ans;
    return 0;
}