#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll ST = 1e17, INF = 1e18-1;
int a[18];

ll cost(ll n)
{
    ll tmp=ST, rtn=0;
    for (int i=17;i>=0;--i,tmp/=10)
        if (a[i])
        {
            rtn+=n/tmp;
            n%=tmp;
        }
    return rtn;
}

void solve()
{
    int n,k,x;
    cin>>n>>k;
    for (int i=0;i<10;++i)
        a[i]=0;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        a[x]=1;
    }
    ll cur = 9;
    while (cost(cur)<=k)
        cur=cur*10+9;
    for (ll tmp=1e17;tmp>0;tmp/=10)
        for (int i=0;i<9&&cur-tmp>0&&cost(cur-tmp)>k;++i)
            cur-=tmp;
    cout<<cur<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}