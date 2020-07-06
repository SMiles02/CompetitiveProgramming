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

int a[200000];

void solve()
{
    int n,k,l=0,r,ones=0,x;
    ll ans=0;
    cin>>n>>k;
    vector<int> v;
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<k;++i)
    {
        cin>>x;
        if (x==1)
            ++ones;
        else
            v.push_back(x);
    }
    sort(a,a+n);
    sort(v.rbegin(), v.rend());
    r=n-1;
    for (int i=0;i<ones;++i)
    {
        ans+=a[r]*2;
        --r;
    }
    for (int i : v)
    {
        ans+=a[r];
        --r;
        ans+=a[l];
        l+=i-1;
    }
    cout<<ans<<"\n";
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