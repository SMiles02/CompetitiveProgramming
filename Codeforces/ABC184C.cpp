#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if (a==c&&b==d)
        cout<<0;
    else if (a+b==c+d||a-b==c-d||abs(a-c)+abs(b-d)<=3)
        cout<<1;
    else if (abs(a-c)+abs(b-d)<=6||abs((a+b)-(c+d))<=3||abs((a-b)-(c-d))<=3||((a+b)&1)==((c+d)&1))
        cout<<2;
    else
        cout<<3;
    return 0;
}