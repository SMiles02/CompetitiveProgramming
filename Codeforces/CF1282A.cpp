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
    int t,a,b,c,r,x,y;
    cin>>t;
    while (t--)
    {
        cin>>a>>b>>c>>r;
        x=c-r;
        y=c+r;
        if (a>b)
        {
            swap(a,b);
        }
        if (a>=x&&b<=y)
        {
            cout<<0;
        }
        else if (a<=x&&b>=y)
        {
            cout<<b-a+x-y;
        }
        else if (b<x||a>y)
        {
            cout<<b-a;
        }
        else if (a>=x)
        {
            cout<<b-y;
        }
        else
        {
            cout<<x-a;
        }
        cout<<"\n";
    }
    return 0;
}