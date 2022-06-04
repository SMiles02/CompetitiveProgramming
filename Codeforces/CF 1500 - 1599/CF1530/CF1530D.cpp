#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5+7;
bitset<N> toGive, toGet;
int a[N], b[N], c[N];

void assignTo(int x, int y)
{
    b[x]=y;
    c[y]=x;
    toGive[x]=toGet[y]=1;
}

void solve()
{
    int n, k;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        toGive[i]=toGet[i]=0;
    }
    for (int i=1;i<=n;++i)
        if (!toGet[a[i]])
            assignTo(i,a[i]);
    vector<int> give, get, both;
    for (int i=1;i<=n;++i)
    {
        if (!toGive[i]&&!toGet[i])
            both.push_back(i);
        else if (!toGive[i])
            give.push_back(i);
        else if (!toGet[i])
            get.push_back(i);
    }
    k=sz(both);
    if (k>1)
    {
        for (int i=0;i<k;++i)
            assignTo(both[i], both[(i+1)%k]);
        both.clear();
    }
    if (k==1&&sz(give))
    {
        assignTo(both[0], get.back());
        assignTo(give.back(), both[0]);
        get.pop_back();
        give.pop_back();
        both.pop_back();
    }
    for (int i=0;i<sz(give);++i)
        assignTo(give[i],get[i]);
    if (!both.empty())
    {
        b[both[0]]=a[both[0]];
        b[c[a[both[0]]]]=both[0];
    }
    k=0;
    for (int i=1;i<=n;++i)
        k+=(a[i]==b[i]);
    cout<<k<<"\n";
    for (int i=1;i<=n;++i)
        cout<<b[i]<<" ";
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