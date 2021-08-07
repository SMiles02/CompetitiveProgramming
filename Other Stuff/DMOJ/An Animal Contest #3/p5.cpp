//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 3e3+5, INF = 1e9;
int n, m, d[N*N];
char s[N][N];
vector<array<int,2>> e[N*N];

void addE(int x, int y, int z)
{
    //cout<<"! "<<x<<" "<<y<<" "<<z<<"\n";
    e[x].push_back({y,z});
    e[y].push_back({x,z});
}

int id(int x, int y)
{
    return x*m+y;
}

int ans(int x)
{
    if (x==INF)
        return 0;
    return x;
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    int x,y;
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            cin>>s[i][j];
            //cout<<id(i,j)<<" ";
            d[id(i,j)]=-1;
        }
        //cout<<"\n";
    }
    for (int i=1;i<=n;++i)
    {
        x=-1;
        for (int j=1;j<=m;++j)
            if (s[i][j]=='#')
            {
                if (x!=-1)
                {
                    if (j-x==1)
                        addE(id(i,j),id(i,x),INF);
                    else
                        addE(id(i,j),id(i,x),j-x-1);
                }
                x=j;
            }
    }
    for (int j=1;j<=m;++j)
    {
        x=-1;
        for (int i=1;i<=n;++i)
            if (s[i][j]=='#')
            {
                if (x!=-1)
                {
                    if (i-x==1)
                        addE(id(i,j),id(x,j),INF);
                    else
                        addE(id(i,j),id(x,j),i-x-1);
                }
                x=i;
            }
    }
    priority_queue<array<int,2>> pq;
    for (int j=1;j<=m;++j)
    {
        if (s[1][j]=='#')
        {
            d[id(1,j)]=INF;
            pq.push({d[id(1,j)],id(1,j)});
        }
    }
    while (!pq.empty())
    {
        y=pq.top()[0];
        x=pq.top()[1];
        pq.pop();
        if (y<d[x])
            continue;
        //cout<<x<<" "<<y<<"\n";
        for (auto i : e[x])
            if (d[i[0]]<min(y,i[1]))
            {
                d[i[0]]=min(y,i[1]);
                pq.push({d[i[0]],i[0]});
            }
    }
    cout<<ans(d[id(n,1)]);
    for (int j=2;j<=m;++j)
        cout<<" "<<ans(d[id(n,j)]);
    cout<<"\n";
    return 0;
}