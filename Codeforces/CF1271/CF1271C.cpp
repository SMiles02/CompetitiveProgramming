#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
        return 1;
    int res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
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
    int t,x,y,a,b,n=0,s=0,e=0,w=0;
    cin>>t>>x>>y;
    while (t--)
    {
        cin>>a>>b;
        if (a>x)
        {
            ++e;
        }
        if (a<x)
        {
            ++w;
        }
        if (b>y)
        {
            ++n;
        }
        if (b<y)
        {
            ++s;
        }
    }
    cout<<max({n,s,e,w})<<"\n";
    if (n==max({n,s,w,e}))
    {
        cout<<x<<" "<<y+1;
    }
    else if (s==max({n,s,w,e}))
    {
        cout<<x<<" "<<y-1;
    }
    else if (e==max({n,s,w,e}))
    {
        cout<<x+1<<" "<<y;
    }
    else if (w==max({n,s,w,e}))
    {
        cout<<x-1<<" "<<y;
    }
    return 0;
}