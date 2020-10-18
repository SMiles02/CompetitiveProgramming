#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    ll n,ans=0,cur,x,y,z,k=(1<<20);
    cin>>n;
    cout<<"1 "<<k<<endl;
    cin>>z;
    z-=(k*n);
    for (int i=0;i<10;++i)
    {
        cur=0;
        x=z;
        for (int j=0;j<20;++j)
            if (j!=i&&j!=i+10)
                cur+=(1<<j);
        cout<<"1 "<<cur<<endl;
        cin>>y;
        x+=y;
        x-=(cur*n);
        x>>=1;
        x/=(1<<i);
        if (x&1)
            ans+=(1<<i);
        x/=(1<<10);
        if (x&1)
            ans+=(1<<(i+10));
    }
    cout<<"2 "<<ans<<endl;
    cin>>x;
}

int main()
{
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}