#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll binpow(ll a, ll b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
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

pair<int,int> a[500];

void solve()
{
    int n,b=1;
    cin>>n;
    int m[2];
    m[0]=0;
    m[1]=0;
    for (int i=0;i<n;++i)
        cin>>a[i].first;
    for (int i=0;i<n;++i)
    {
        cin>>a[i].second;
        ++m[a[i].second];
    }
    for (int i=1;i<n;++i)
        if (a[i].first<a[i-1].first)
            b=0;
    if ((m[0]&&m[1])||b)
        cout<<"Yes\n";
    else
        cout<<"No\n";
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