#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int p[61];

void update(int n, int k)
{
    for (int i=2;i<=n;++i)
        while (n%i==0)
        {
            n/=i;
            p[i]+=k;
        }
}

ll c(int n, int k)
{
    ll ret=1;
    for (int i=1;i<=60;++i)
        p[i]=0;
    for (int i=1;i<=k;++i)
        update(i,-1);
    for (int i=1;i<=n-k;++i)
        update(i,-1);
    for (int i=1;i<=n;++i)
        update(i,1);
    for (int i=2;i<61;++i)
        for (int j=0;j<p[i];++j)
            ret*=i;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b;
    ll k;
    cin>>a>>b>>k;
    while (a>0||b>0)
    {
        //cout<<a<<" "<<b<<" "<<k<<"\n";
        if (a==0)
        {
            cout<<"b";
            --b;
        }
        else if (b==0)
        {
            cout<<"a";
            --a;
        }
        else if (c(a+b-1,a-1)<k)
        {
            //cout<<c(a+b-1,a-1)<<"\n";
            k-=c(a+b-1,a-1);
            cout<<"b";
            --b;
        }
        else
        {
            cout<<"a";
            --a;
        }
    }
    return 0;
}