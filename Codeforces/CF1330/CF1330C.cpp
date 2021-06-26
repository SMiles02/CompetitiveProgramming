#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
        return res * a;
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
    int n,m;
    cin>>n>>m;
    int a[m];
    ll s=0;
    for (int i=0;i<m;++i)
    {
        cin>>a[i];
        if (a[i]+i>n)
        {
            cout<<-1;
            return 0;
        }
        s+=a[i];
    }
    if (s<n)
    {
        cout<<-1;
        return 0;
    }
    int ans[m];
    ans[0]=1;
    cout<<"1 ";
    for (int i=1;i<m;++i)
    {
        ans[i]=ans[i-1]+a[i-1];
        if (s-ans[i]+i+1>=n)
        {
            ans[i]=i+1;
            s-=(ans[i-1]+a[i-1]-i-1);
        }
        else
        {
            ans[i]-=(s-n);
            s=n;
        }
        cout<<ans[i]<<" ";
    }
    return 0;
}