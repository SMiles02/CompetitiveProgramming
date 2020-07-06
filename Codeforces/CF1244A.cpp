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
    int t,a,b,c,d,k,x,y;
    cin>>t;
    while (t--)
    {
        cin>>a>>b>>c>>d>>k;
        x=0;y=0;
        if (a%c)
        {
            ++x;
        }
        if (b%d)
        {
            ++y;
        }
        x+=(a/c);
        y+=(b/d);
        if (x+y>k)
        {
            cout<<"-1\n";
        }
        else
        {
            cout<<x<<" "<<y<<"\n";
        }
    }
    return 0;
}