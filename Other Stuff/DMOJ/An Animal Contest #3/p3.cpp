//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
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
    int n,x,y;
    cin>>n;
    int a[n],b[n];
    for (int i=0;i<n;++i)
        cin>>b[i];
    sort(b,b+n);
    x=0;y=n-1;
    for (int i=0;i<n;++i)
    {
        if (i&1)
            a[i]=b[y--];
        else
            a[i]=b[x++];
    }
    cout<<a[0];
    for (int i=1;i<n;++i)
        cout<<" "<<a[i];
    cout<<"\n";
    for (int i=0;i<n;++i)
    {
        if (i&1)
            cout<<"S";
        else if (i+1<n)
            cout<<"B";
        else
            cout<<"E";
    }
    cout<<"\n";
    return 0;
}