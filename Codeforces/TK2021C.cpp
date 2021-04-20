#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e5+69;
int f[N],ans[N];
vector<int> v[N],indi[N],team[N];

void solve()
{
    int n,m,k,x;  
    cin>>n>>m;
    for (int i=1;i<=n;++i)
    {
        f[i]=0;
        indi[i].clear();
        team[i].clear();
    }
    for (int i=0;i<m;++i)
    {
        cin>>k;
        v[i].clear();
        ans[i]=0;
        for (int j=0;j<k;++j)
        {
            cin>>x;
            ++f[x];
            v[i].push_back(x);
        }
        if (k==1)
            indi[v[i][0]].push_back(i);
        else
            for (int j=0;j<k;++j)
                team[v[i][j]].push_back(i);
    }
    for (int i=1;i<=n;++i)
    {
        if (f[i]<(m+1)/2)
            continue;
        if (sz(indi[i])>(m+1)/2)
        {
            cout<<"NO\n";
            return;
        }
        x=0;
        for (int j : indi[i])
        {
            ++x;
            ans[j]=i;
        }
        for (int j=0;j<sz(team[i]);++j)
            if (x<(m+1)/2)
            {
                ans[team[i][j]]=i;
                ++x;
            }
        cout<<"YES\n";
        for (int j=0;j<m;++j)
        {
            if (ans[j]==0)
            {
                if (v[j][0]==i)
                    ans[j]=v[j][1];
                else
                    ans[j]=v[j][0];
            }
            cout<<ans[j]<<" ";
        }
        cout<<"\n";
        return;
    }
    cout<<"YES\n";
    for (int i=0;i<m;++i)
        cout<<v[i][0]<<" ";
    cout<<"\n"; 
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