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
    double vP,vD,t,f,c,distance,d,x;
    int dropped=0;
    cin>>vP;
    cin>>vD;
    cin>>t;
    cin>>f;
    cin>>c;
    if (vP>=vD)
    {
        cout<<0;
        return 0;
    }
    distance=vP*t;
    x=vD-vP;
    while (1)
    {
        d=distance*vP;
        d/=x;
        distance+=d;
        if (distance>=c)
        {
            cout<<dropped;
            return 0;
        }
        ++dropped;
        distance+=(((distance/vD)+f)*vP);
    }
    return 0;
}