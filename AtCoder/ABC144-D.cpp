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
    int a,b,x;
    double k,t,pi=3.14159265359,r,d;
    cin>>a>>b>>x;
    k=2*x-(a*a*b);
    k/=(a*a);
    //cout<<"k: "<<k<<"\n";
    if (k>=0)
    {
        t=b*b+k*k+a*a;
        t-=(2*b*k);
        t=sqrt(t);
        //cout<<"t: "<<t<<"\n";
        r=a/t;
        //cout<<"r: "<<r<<"\n";
    }
    else
    {
        k=2*x;
        k/=(a*b);
        //cout<<"new k: "<<k<<"\n";
        t=(k*k+b*b);
        t=sqrt(t);
        //cout<<t<<"\n";
        r=k/t;
        //cout<<"r: "<<r<<"\n";
    }
    r=asin(r);
    //cout<<"r (asined): "<<r<<"\n";
    d=r*180;
    d/=pi;
    cout<<setprecision(10)<<90-d;
    return 0;
}