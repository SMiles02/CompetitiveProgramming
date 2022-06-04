#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,a[100],ans[100];

void f(int l, int r, int d)
{
    if (l>r)
        return;
    int m=0;
    for (int i=l;i<=r;++i)
        m=max(a[i],m);
    for (int i=l;i<=r;++i)
        if (a[i]==m)
        {
            ans[i]=d;
            f(l,i-1,d+1);
            f(i+1,r,d+1);
            return;
        }
}

void solve()
{
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i];
    f(0,n-1,0);
    for (int i=0;i<n;++i)
        cout<<ans[i]<<" ";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}