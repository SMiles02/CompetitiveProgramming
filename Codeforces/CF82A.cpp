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
    int n,cur=1;
    cin>>n;
    while (n-(5*cur)>0)
    {
        n-=(5*cur);
        cur*=2;
    }
    if (n<=cur)
    {
        cout<<"Sheldon";
        return 0;
    }
    if (n<=2*cur)
    {
        cout<<"Leonard";
        return 0;
    }
    if (n<=3*cur)
    {
        cout<<"Penny";
        return 0;
    }
    if (n<=4*cur)
    {
        cout<<"Rajesh";
        return 0;
    }
    if (n<=5*cur)
    {
        cout<<"Howard";
        return 0;
    }
    return 0;
}