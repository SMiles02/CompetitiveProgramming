//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

int RNG(int x, int y)
{
    return uniform_int_distribution<int>(x,y)(rng);
}

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
    int t=50,d,n,k,h,l,r;
    cout<<t<<"\n";
    while (t--)
    {
        d=RNG(4,6);
        n=RNG(7,9);
        k=RNG(2,4);
        cout<<d<<" "<<n<<" "<<k<<"\n";
        while (n--)
        {
            h=RNG(1,100);
            l=RNG(1,d);
            r=RNG(l,d);
            cout<<h<<" "<<l<<" "<<r<<"\n";
        }
    }
    return 0;
}