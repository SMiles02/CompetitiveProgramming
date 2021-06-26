#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 2e5+1;
vector<int> edges[mn];
bitset<mn> done;

void dfs(int c)
{
    done[c]=1;
    cout<<c<<" ";
    for (int i : edges[c])
        if (!done[i])
            dfs(i);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,b;
    cin>>n;
    array<int,2> c[n+1];
    vector<int> v;
    for (int i=1;i<=n;++i)
    {
        cin>>a>>b;
        c[i]={a,b};
        edges[a].push_back(b);
        edges[b].push_back(a);
        if (a==1||b==1)
            v.push_back(1^a^b);
    }
    done[1]=1;
    cout<<"1 ";
    for (int i=0;i<2;++i)
        for (int j=0;j<2;++j)
            if (v[i]==c[1][j])
            {
                dfs(v[i]);
                return 0;
            }
    return 0;
}