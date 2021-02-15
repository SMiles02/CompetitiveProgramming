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

int n,m;
ll k;
int a[1000];
string s[1000];

ll check(int x)
{
    ll su=0;
    vector<int> v;
    for (int j=0;j<m;++j)
    {
        v.clear();
        for (int i=0;i<n;++i)
            if (s[i][j]=='1')
                v.push_back(a[i]);
        sort(v.rbegin(), v.rend());
        for (int i=0;i<min(sz(v),x);++i)
            su+=v[i];
    }
    return su;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<n;++i)
        cin>>s[i];
    int l=1,r=n,m;
    if (check(n)<k)
    {
        cout<<-1;
        return 0;
    }
    while (l<r)
    {
        m=l+(r-l)/2;
        if (check(m)<k)
            l=m+1;
        else
            r=m;
    }
    cout<<l;
    return 0;
}