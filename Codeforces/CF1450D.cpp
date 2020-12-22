#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[n+2],l[n+2],ans[n+2],f[n+2];
    f[0]=0;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        ans[i]=0;
        f[i]=0;
    }
    a[0]=0;a[n+1]=0;
    stack<int> s;
    s.push(0);
    for (int i=1;i<=n;++i)
    {
        while (a[s.to p()]>=a[i])
            s.pop();
        l[i]=s.top();
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    s.push(n+1);
    for (int i=n;i;--i)
    {
        while (a[s.top()]>=a[i])
            s.pop();
        ans[a[i]]=max(ans[a[i]],s.top()-l[i]-1);
        s.push(i);
    }
    for (int i=1;i<=n;++i)
        ++f[min(ans[i],n-i+1)];
    for (int i=n-1;i;--i)
        f[i]+=f[i+1];
    for (int i=1;i<=n;++i)
    {
        if (i+f[i]-1==n)
            cout<<1;
        else
            cout<<0;
    }
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