#include <bits/stdc++.h>
#define ll long long
#define D array<ll,2>
using namespace std;

const int N = 1e5+7, MOD = 1e9+7;
int f[N][3], x;
ll d[N], y;
vector<array<int,2>> e[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,a,b,c;
    cin>>n>>m;
    while (m--)
    {
        cin>>a>>b>>c;
        e[a].push_back({b,c});
    }
    priority_queue<D,vector<D>,greater<D>> pq;
    for (int i=2;i<=n;++i)
    {
        d[i]=1e18;
        f[i][1]=n+1;
        f[i][2]=0;
    }
    d[1]=0;
    f[1][0]=1;
    f[1][1]=0;
    pq.push({0,1});
    while (!pq.empty())
    {
        x=pq.top()[1];
        y=pq.top()[0];
        pq.pop();
        if (d[x]<y)
            continue;
        for (auto i : e[x])
        {
            if (y+i[1]==d[i[0]])
            {
                f[i[0]][0]+=f[x][0];
                if (f[i[0]][0]>=MOD)
                    f[i[0]][0]-=MOD;
                f[i[0]][1]=min(f[i[0]][1],f[x][1]+1);
                f[i[0]][2]=max(f[i[0]][2],f[x][2]+1);
            }
            if (y+i[1]<d[i[0]])
            {
                d[i[0]]=y+i[1];
                f[i[0]][0]=f[x][0];
                f[i[0]][1]=f[x][1]+1;
                f[i[0]][2]=f[x][2]+1;
                pq.push({d[i[0]],i[0]});
            }
        }
    }
    cout<<d[n]<<" "<<f[n][0]<<" "<<f[n][1]<<" "<<f[n][2];
    return 0;
}