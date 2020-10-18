#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

vector<int> p[500001],edges[1000001];
int done[1000001];

void dfs(int c, int k)
{
    ++done[c];
    if (k)
        ++done[c];
    for (int i : edges[c])
        if (!done[i])
            dfs(i,k^1);
}

int main()
{
    int n,k;
    cin>>n;
    if (!(n&1))
    {
        cout<<"First"<<endl;
        for (int i=1;i<=n;++i)
            cout<<i<<" ";
        for (int i=1;i<n;++i)
            cout<<i<<" ";
        cout<<n<<endl;
        cin>>k;
        return 0;
    }
    cout<<"Second"<<endl;
    for (int i=1;i<=2*n;++i)
    {
        cin>>k;
        p[k].push_back(i);
    }
    for (int i=1;i<=n;++i)
    {
        edges[p[i][0]].push_back(p[i][1]);
        edges[p[i][1]].push_back(p[i][0]);
        edges[i].push_back(i+n);
        edges[i+n].push_back(i);
    }
    for (int i=1;i<=2*n;++i)
        if (!done[i])
            dfs(i,0);
    ll s=0;
    for (int i=1;i<=n;++i)
    {
        if (done[p[i][0]]==2)
            s+=p[i][0];
        else
            s+=p[i][1];
    }
    if (s%(2*n))
        for (int i=1;i<=n;++i)
        {
            if (done[p[i][0]]==2)
                cout<<p[i][1]<<" ";
            else
                cout<<p[i][0]<<" ";
        }
    else
        for (int i=1;i<=n;++i)
        {
            if (done[p[i][0]]==2)
                cout<<p[i][0]<<" ";
            else
                cout<<p[i][1]<<" ";
        }
    cout<<endl;
    cin>>k;
    return 0;
}