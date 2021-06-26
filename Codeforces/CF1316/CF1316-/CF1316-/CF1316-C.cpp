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
    int n,m,p,x=10000000,y=10000000,k;
    cin>>n>>m>>p;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        if (k%p)
        {
            x=min(x,i);
        }
    }
    for (int i=0;i<m;++i)
    {
        cin>>k;
        if (k%p)
        {
            y=min(y,i);
        }
    }
    //cout<<x<<" "<<y<<"\n";
    cout<<x+y;
    return 0;
}