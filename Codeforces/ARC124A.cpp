//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

const int MOD = 998244353;

int mul(int a, int b)
{
    return (1LL*a*b)%MOD;
}

ll binpow(ll a, ll b)
{
    //cout<<a<<" ^ "<<b<<"\n";
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = mul(res, a);
        a = mul(a, a);
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
    int n,k,ans=1,opt;
    cin>>n>>k;
    opt=k;
    vector<pair<int,char>> v(k+2);
    for (int i=1;i<=k;++i)
    {
        cin>>v[i].second>>v[i].first;
        if (v[i].second=='L')
            --opt;
    }
    v[0]={0 ,'X'};
    v[k+1]={n+1, 'X'};
    sort(v.begin(), v.end());
    for (int i=1;i<=k+1;++i)
    {
        ans=mul(ans,binpow(opt,v[i].first-v[i-1].first-1));
        //cout<<v[i].first<<" "<<v[i].second<<"\n";
        if (v[i].second=='L')
            ++opt;
        else if (v[i].second=='R')
            --opt;
        //cout<<"opt: "<<opt<<"\n";
    }
    cout<<ans;
    return 0;
}