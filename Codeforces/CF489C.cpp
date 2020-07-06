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
    int m,s,x;
    cin>>m>>s;
    if (m*9<s)
    {
        cout<<"-1 -1";
        return 0;
    }
    if (s==0&&m!=1)
    {
        cout<<"-1 -1";
        return 0;
    }
    if (m==1)
    {
        cout<<s<<" "<<s;
        return 0;
    }
    int a[m];
    int b[m];
    x=s;
    for (int i=0;i<m;++i)
    {
        a[i]=min(9,x);
        x-=a[i];
    }
    b[0]=1;
    for (int i=1;i<m-1;++i)
    {
        b[i]=0;
    }
    b[m-1]=s-1;
    for (int i=m-1;b[i]>9;--i)
    {
        b[i-1]+=b[i]-9;
        b[i]=9;
    }
    for (int i=0;i<m;++i)
    {
        cout<<b[i];
    }
    cout<<" ";
    for (int i=0;i<m;++i)
    {
        cout<<a[i];
    }
    return 0;
}