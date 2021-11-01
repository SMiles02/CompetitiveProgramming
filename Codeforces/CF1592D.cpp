#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+3;
int t, od[N], p[N];
vector<int> e[N];

void dfs(int c, int x)
{
    p[c]=x;
    od[++t]=c;
    for (int i : e[c])
        if (i!=x)
            dfs(i,c);
}

int main()
{
    int n,x,y,l,r,m;
    cin>>n;
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1,0);
    cout<<"? "<<n;
    for (int i=1;i<=n;++i)
        cout<<" "<<i;
    cout<<endl;
    cin>>x;
    l=2;r=n;
    while (l<r)
    {
        m=l+(r-l)/2;
        cout<<"? "<<m;
        for (int i=1;i<=m;++i)
            cout<<" "<<od[i];
        cout<<endl;
        cin>>y;
        if (x==y)
            r=m;
        else
            l=m+1;
    }
    cout<<"! "<<od[l]<<" "<<p[od[l]]<<endl;
    return 0;
}