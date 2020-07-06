#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,c,m=1,ans=0,low=696969,k,t=1;

void primeF()
{
    for (int i=2;i<=sqrt(n);++i)
    {
        if (n%i==0)
        {
            c=0;
            while (n%i==0)
            {
                ++c;
                n/=i;
            }
            low=min(low,c);
            t*=i;
            m=max(c,m);
        }
    }
    if (n>1)
    {
        low=1;
        t*=n;
    }
    //cout<<m<<"\n";
}

void highPow()
{
    while (1)
    {
        if (ceil(log2(m)) == floor(log2(m)))
        {
            return;
        }
        ++m;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    k=n;
    if (n==1)
    {
        cout<<"1 0";
        return 0;
    }
    primeF();
    if (m==1)
    {
        cout<<t<<" "<<0;
        return 0;
    }
    highPow();
    cout<<t<<" ";
    if (m!=low)
    {
        ans=1;
    }
    while (m>1)
    {
        m/=2;
        ++ans;
    }
    cout<<ans;
    return 0;
}