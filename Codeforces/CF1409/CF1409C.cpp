#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int a[50],INF=1e9,x,y,n,k;

int attempt(int s, int t)
{
    if ((y-x)%(t-s))
        return INF;
    k=(y-x)/(t-s);
    a[0]=y-(k*t);
    for (int i=1;i<n;++i)
        a[i]=a[i-1]+k;
    if (a[0]<1)
        return INF;
    return a[n-1];
}

void solve()
{
    int ans=INF,f=0,g=0,c;
    cin>>n>>x>>y;
    for (int i=0;i<n;++i)
        for (int j=i+1;j<n;++j)
        {
            c=attempt(i,j);
            if (c<ans)
            {
                ans=c;
                f=i;
                g=j;
            }
        }
    c=attempt(f,g);
    for (int i=0;i<n;++i)
        cout<<a[i]<<" ";
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