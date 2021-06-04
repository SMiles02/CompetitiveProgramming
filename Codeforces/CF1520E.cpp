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

void solve()
{
    int n,k;
    ll ans=0;
    cin>>n;
    string s;
    cin>>s;
    vector<int> v;
    for (int i=0;i<n;++i)
        if (s[i]=='*')
            v.push_back(i);
    k=sz(v);
    if (k==0)
    {
        cout<<"0\n";
        return;
    }
    for (int i=0;i<k/2;++i)
    {
        //cout<<v[i]<<" "<<v[k/2]-k/2+i<<"\n";
        ans+=v[k/2]-k/2+i-v[i];
    }
    for (int i=k/2+1;i<k;++i)
    {
        //cout<<v[i]<<" "<<v[k/2]+i-k/2<<"\n";
        ans+=v[i]-v[k/2]-i+k/2;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}