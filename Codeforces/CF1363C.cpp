#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int e[1001];
bool edges[1001][1001];

void solve()
{
    int n,x,u,v,b;
    cin>>n>>x;
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=n;++j)
            edges[i][j]=0;
        e[i]=0;
    }
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u][v]=1;
        edges[v][u]=1;
        ++e[u];
        ++e[v];
    }
    for (int z=1;1;++z)
    {
        if (e[x]<2)
        {
            if (z%2)
                cout<<"Ayush\n";
            else
                cout<<"Ashish\n";
            return;
        }
        b=0;
        for (int i=1;i<=n;++i)
            if (0<=e[i]&&e[i]<2)
            {
                if ((edges[i][x]&&e[x]>2)||!(edges[i][x]))
                {
                    b=1;
                    e[i]=-1;
                    for (int j=1;j<=n;++j)
                        if (edges[i][j])
                        {
                            --e[j];
                            edges[i][j]=0;
                            edges[j][i]=0;
                        }
                    break;
                }
            }
        if (!b)
        {
            if (z%2==0)
                cout<<"Ayush\n";
            else
                cout<<"Ashish\n";
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}