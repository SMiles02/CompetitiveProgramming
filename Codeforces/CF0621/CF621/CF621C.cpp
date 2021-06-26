#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
    }
    return res;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
string to_upper(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,p,l,r;
    double ans=0,cur;
    cin>>n>>p;
    ll a[n];
    ll b[n];
    for (int i=0;i<n;++i)
    {
        cin>>l>>r;
        if (!(l%p))
        {
            a[i]=(r/p)-(l/p)+1;
        }
        else
        {
            a[i]=(r/p)-(l/p);
        }
        b[i]=r-l+1;
        cout<<a[i]<<" "<<b[i]<<"\n";
    }
    for (int i=0;i<n;++i)
    {
        cur=1000*a[i];
        cur/=b[i];
        ans+=cur;
    }
    for (int i=n-1;i+1;--i)
    {
        cur=1000*a[i]*a[(i+n-1)%n];
        cur/=b[i];
        cur/=b[(i+n-1)%n];
        ans-=cur;
    }
    cout<<setprecision(20)<<ans;
    return 0;
}