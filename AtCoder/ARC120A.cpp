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
    int n,x=0;
    cin>>n;
    ll a[n],s=0,t;
    priority_queue<ll> pq;
    cin>>a[0];
    s+=a[0]*2;
    x=a[0];
    t=a[0];
    cout<<s<<"\n";
    for (int i=1;i<n;++i)
    {
        cin>>a[i];
        if (a[i]>x)
        {
            s+=1LL*i*(a[i]-x);
            //cout<<"plus "<<1LL*i*(a[i]-x)<<"\n";
            x=a[i];
        }
        t+=a[i];
        s+=t+x;
        cout<<s<<"\n";
    }
    return 0;
}