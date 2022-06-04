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
    int n,m=1e9,k;
    cin>>n;
    int a[n];
    vector<int> v;
    vector<int> w;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        m=min(a[i],m);
    }
    for (int i=0;i<n;++i)
        if (!(a[i]%m))
        {
            v.push_back(a[i]);
            w.push_back(i);
        }
    sort(v.begin(), v.end());
    k=sz(v);
    for (int i=0;i<k;++i)
        a[w[i]]=v[i];
    for (int i=1;i<n;++i)
        if (a[i-1]>a[i])
        {
            cout<<"NO\n";
            return;
        }
    cout<<"YES\n";
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