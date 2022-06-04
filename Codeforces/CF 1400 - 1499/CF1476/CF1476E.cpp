#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 1e5+7;
vector<int> from[mn];
int n,m,k,x,y,to[mn];

bool equals(string& s, string& t)
{
    for (int i=0;i<k;++i)
        if (s[i]!=t[i]&&s[i]!='_'&&t[i]!='_')
            return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    string s[n+1],t,u;
    map<string,int> mp;
    for (int i=1;i<=n;++i)
    {
        cin>>s[i];
        mp[s[i]]=i;
    }
    while (m--)
    {
        cin>>t>>x;
        if (!equals(s[x],t))
        {
            cout<<"NO";
            return 0;
        }
        for (int i=0;i<(1<<k);++i)
        {
            u=t;
            for (int j=0;j<k;++j)
                if (i&(1<<j))
                    u[j]='_';
            y=mp[u];
            if (y==0||y==x)
                continue;
            from[x].push_back(y);
            ++to[y];
        }
    }
    vector<int> ans;
    stack<int> topo;
    for (int i=1;i<=n;++i)
        if (to[i]==0)
            topo.push(i);
    while (!topo.empty())
    {
        x=topo.top();
        topo.pop();
        ans.push_back(x);
        for (int i : from[x])
            if (--to[i]==0)
                topo.push(i);
    }
    if (sz(ans)<n)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    for (int i : ans)
        cout<<i<<" ";
    return 0;
}