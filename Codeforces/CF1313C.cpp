#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

ll min(ll a, ll b)
{
    if (a>b)
        return b;
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,cur,x;
    cin>>n;
    ll a[n];
    ll l[n];
    ll r[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    l[0]=0;
    r[n-1]=0;
    cur=a[0];
    set<int> s;
    s.insert(a[0]);
    set<int>::iterator it;
    for (int i=1;i<n;++i)
    {
        if (cur>a[i])
        {
            it=s.lower_bound(a[i]);
            if (it==s.begin())
            {
                l[i]=a[i]*i;
                cur=a[i];
            }
            else
            {
                --it;
                l[i]=(*it)*i;
                cur=*it;
            }
        }
        else
        {
            l[i]=l[i-1]+cur;
            cur=a[i];
        }
        s.insert(a[i]);
        cout<<"l["<<i<<"] = "<<l[i]<<"\n";
    }
    cur=a[n-1];
    ll ans=l[n-1]+r[n-1]+a[n-1];
    x=n-1;
    for (int i=2;i<=n;++i)
    {
        if (cur>a[n-i])
            r[n-i]=a[n-i]*(i-1);
        else
            r[n-i]=r[n-i+1]+cur;
        cur=a[n-i];
        if (l[n-i]+r[n-i]+a[n-i]>ans)
        {
            ans=l[n-i]+r[n-i]+a[n-i];
            x=n-i;
        }
        cout<<n-i<<": "<<l[n-i]+r[n-i]+a[n-i]<<"\n";
        cout<<l[n-i]<<" "<<a[n-i]<<" "<<r[n-i]<<"\n";
    }
    cout<<x<<"!!!\n";
    for (int i=x-1;i>=0;--i)
        a[i]=min(a[i],a[i+1]);
    for (int i=x+1;i<n;++i)
        a[i]=min(a[i],a[i-1]);
    cout<<ans<<"\n";
    for (int i=0;i<n;++i)
        cout<<a[i]<<" ";
    return 0;
}