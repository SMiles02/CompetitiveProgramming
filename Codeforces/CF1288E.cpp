#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

bool called[300001];
int lastCalled[300001];
int maxi[300001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k;
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        maxi[i]=i;
    for (int i=1;i<=m;++i)
    {
        cin>>k;
        if (called[k])
            maxi[k]=max(i-lastCalled[k],maxi[i]);
        else
            maxi[k]+=i-1;
        maxi[k]=min(n,maxi[k]);
        called[k]=1;
        lastCalled[k]=i;
        cout<<k<<": "<<maxi[k]<<"\n";
    }
    for (int i=1;i<=n;++i)
    {
        k=i;
        if (called[k])
            maxi[k]=max(m-lastCalled[k]+1,maxi[k]);
        else
            maxi[k]+=m;
        maxi[k]=min(n,maxi[k]);
        if (called[i])
            cout<<"1 ";
        else
            cout<<i<<" ";
        cout<<maxi[i]<<"\n";
    }
    return 0;
}