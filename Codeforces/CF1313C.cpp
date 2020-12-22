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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    ll a[n],l[n],r[n],ans=0;
    for (int i=0;i<n;++i)
        cin>>a[i];
    stack<int> s;
    for (int i=0;i<n;++i)
    {
        while ((!s.empty())&&a[s.top()]>a[i])
            s.pop();
        if (s.empty())
            l[i]=a[i]*(i+1);
        else
            l[i]=l[s.top()]+(i-s.top())*a[i];
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (int i=n-1;i>=0;--i)
    {
        while ((!s.empty())&&a[s.top()]>a[i])
            s.pop();
        if (s.empty())
            r[i]=a[i]*(n-i);
        else
            r[i]=r[s.top()]+(s.top()-i)*a[i];
        s.push(i);
        ans=max(ans,l[i]+r[i]-a[i]);
    }
    for (int i=0;i<n;++i)
        if (l[i]+r[i]-a[i]==ans)
        {
            for (int j=i-1;j>=0;--j)
                a[j]=min(a[j],a[j+1]);
            for (int j=i+1;j<n;++j)
                a[j]=min(a[j],a[j-1]);
            for (int j=0;j<n;++j)
                cout<<a[j]<<" ";
            return 0;
        }
    return 0;
}