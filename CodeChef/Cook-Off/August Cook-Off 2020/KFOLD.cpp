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

void solve()
{
    int n,k,z=0,o=0,x;
    string s;
    cin>>n>>k;
    cin>>s;
    for (auto c : s)
    {
        if (c=='0')
            ++z;
        else
            ++o;
    }
    if (o%(n/k)||z%(n/k))
    {
        cout<<"IMPOSSIBLE\n";
        return;
    }
    int ans[n];
    for (int i=0;i<k;++i)
    {
        if (z)
        {
            x=0;
            z-=(n/k);
        }
        else
        {
            x=1;
            o-=(n/k);
        }
        for (int j=i;j<n;j+=2*k)
            ans[j]=x;
        for (int j=2*k-i-1;j<n;j+=2*k)
            ans[j]=x;
    }
    for (int i=0;i<n;++i)
        cout<<ans[i];
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}