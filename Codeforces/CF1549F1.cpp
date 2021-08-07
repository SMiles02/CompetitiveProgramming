#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
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
    int n;
    ll A,B,ans=0;
    cin>>n;
    ll a[n][2];
    for (int i=0;i<n;++i)
        for (int j=0;j<2;++j)
            cin>>a[i][j];
    for (int i=0;i<n;++i)
        for (int j=i+1;j<n;++j)
            for (int k=j+1;k<n;++k)
            {
                A = abs(a[i][0]*(a[j][1]-a[j][2])+a[i][1]*(a[j][2]-a[j][0])+a[i][2]*(a[j][0]-a[j][1]));
                B = gcd(abs(a[i][0]-a[j][0]),abs(a[i][1]-a[j][1])) + gcd(abs(a[i][0]-a[k][0]),abs(a[i][1]-a[k][1])) + gcd(abs(a[k][0]-a[j][0]),abs(a[k][1]-a[j][1]));
                if (((A-B)/2-1)&1)
                    ++ans;
            }
    cout<<ans;
    return 0;
}