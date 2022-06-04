#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

const int mill = 1e6;
int addAmt[mill+2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,ans=1e9;
    cin>>n>>m;
    pii a[n+1],b[m];
    for (int i=0;i<n;++i)
        cin>>a[i].f>>a[i].s;
    for (int i=0;i<m;++i)
        cin>>b[i].f>>b[i].s;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            if (a[i].f<=b[j].f&&a[i].s<=b[j].s)
                addAmt[b[j].f-a[i].f]=max(addAmt[b[j].f-a[i].f],b[j].s-a[i].s+1);
    ans=min(ans,addAmt[mill+1]+mill+1);
    for (int i=mill;i+1;--i)
    {
        addAmt[i]=max(addAmt[i],addAmt[i+1]);
        ans=min(ans,i+addAmt[i]);
    }
    cout<<ans<<"\n";
    return 0;
}