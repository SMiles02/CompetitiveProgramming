#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int range[33][2];
vector<array<int,2>> edges[33];
bitset<33> done[33];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int l,r,n,m=0,d=1,rD;
    cin>>l>>r;
    n=min(l+1,32);
    for (int i=2;i<n;++i)
    {
        edges[i].push_back({i+1,1});
        done[i][i+1]=1;
    }
    edges[1].push_back({2,l-n+2});
    done[1][2]=1;
    rD=l;
    range[2][0]=range[2][1]=l-n+2;
    m=n-1;
    d=1;
    for (int i=3;i<=n;++i)
        range[i][0]=range[i][1]=range[i-1][0]+1;
    for (int i=1;i<=n&&r-rD>d;++i)
        for (int j=i+2;j<=n&&r-rD>d;++j)
        {
            //cout<<i<<" "<<j<<"\n";
            done[i][j]=1;
            edges[i].push_back({j,range[j][1]+1-range[i][0]});
            ++m;
            for (int k=j;k<=n;++k)
            {
                range[k][1]+=range[i][1]-range[i][0]+1;
                rD=max(d,range[k][1]-range[k][0]+1);
            }
            //cout<<i<<" "<<j<<" "<<range[4][1]<<"\n";
            rD=range[n][1];
        }
    for (int i=1;i<=n;++i)
        for (int j=i+1;j<=n;++j)
            if (!done[i][j]&&r-rD==range[i][1]-range[i][0]+1)
            {
                edges[i].push_back({j,r-range[i][1]});
                rD=r;
                ++m;
            }
    if (d^r)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<n<<" "<<m<<"\n";
    for (int i=1;i<=n;++i)
        for (auto j : edges[i])
            cout<<i<<" "<<j[0]<<" "<<j[1]<<"\n";
    return 0;
}