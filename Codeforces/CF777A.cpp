#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
        return res * a;
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
    int n,x;
    cin>>n;
    cin>>x;
    if (n%6==0)
    {
        if (x==0)
            cout<<0;
        else if (x==1)
            cout<<1;
        else
            cout<<2;
    }
    if (n%6==1)
    {
        if (x==0)
            cout<<1;
        else if (x==1)
            cout<<0;
        else
            cout<<2;
    }
    if (n%6==2)
    {
        if (x==0)
            cout<<1;
        else if (x==1)
            cout<<2;
        else
            cout<<0;
    }
    if (n%6==3)
    {
        if (x==0)
            cout<<2;
        else if (x==1)
            cout<<1;
        else
            cout<<0;
    }
    if (n%6==4)
    {
        if (x==0)
            cout<<2;
        else if (x==1)
            cout<<0;
        else
            cout<<1;
    }
    if (n%6==5)
    {
        if (x==0)
            cout<<0;
        else if (x==1)
            cout<<2;
        else
            cout<<1;
    }
    return 0;
}