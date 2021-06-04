#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int dp[100001][5][16][5];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k,n,m,o,x,y,z,a,b;
    cin>>k>>n>>m>>o;
    for (int g=0;g<100001;++g)
        for (int h=0;h<5;++h)
            for (int i=0;i<16;++i)
                for (int j=0;j<5;++j)
                    dp[g][h][i][j]=INF;
    while (m--)
    {
        cin>>x>>y>>z;
        dp[x/k][x%k][0][y%k]=z;
    }
    for (int i=1;i<16;++i)
        for (int g=0;g<=n/k;++g)
            for (int h=0;h<k;++h)
                for (int j=0;j<k;++j)
                    for (int f=0;f<k;++f)
                        dp[g][h][i][j]=min(dp[g][h][i][j],dp[g][h][i-1][f]+dp[g+(1<<(i-1))][f][i-1][j]);
    while (o--)
    {
        cin>>x>>y;
        a=x/k;
        b=y/k;
        vector<int> v(k,INF);
        v[x%k]=0;
        for (int h=15;h>=0;--h)
            if (a+(1<<h)<=b)
            {
                vector<int> w(k,INF);
                for (int i=0;i<k;++i)
                    for (int j=0;j<k;++j)
                        w[j]=min(w[j],v[i]+dp[a][i][h][j]);
                swap(v,w);
                a+=(1<<h);
            }
        if (v[y%k]==INF)
            v[y%k]=-1;
        cout<<v[y%k]<<"\n";
    }
    return 0;
}