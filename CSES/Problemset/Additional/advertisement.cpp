#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    ll ans=0;
    int a[n+2],l[n+2];
    a[0]=a[n+1]=0;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    stack<int> s,t;
    s.push(0);
    for (int i=1;i<=n;++i)
    {
        while (a[s.top()]>=a[i])
            s.pop();
        l[i]=s.top();
        s.push(i);
    }
    t.push(n+1);
    for (int i=n;i;--i)
    {
        while (a[t.top()]>=a[i])
            t.pop();
        ans=max(ans,1LL*(t.top()-l[i]-1)*a[i]);
        t.push(i);
    }
    cout<<ans;
    return 0;
}