#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
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

void solve()
{
    int n,cur=-1;
    cin>>n;
    if (n%4)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    int a[n+1];
    for (int i=n/2+1;i<=3*(n/4);++i)
    {
        cur+=2;
        a[i]=cur;
    }
    --cur;
    for (int i=1;i<=n/2;++i)
    {
        cur+=2;
        a[i]=cur;
    }
    --cur;
    for (int i=3*(n/4)+1;i<=n;++i)
    {
        cur+=2;
        a[i]=cur;
    }
    for (int i=1;i<=n;++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}