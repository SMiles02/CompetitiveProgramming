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

void solve()
{
    int n,k;
    cin>>n>>k;
    if (n<k)
    {
        cout<<"NO\n";
        return;
    }
    if (n%2&&k%2&&n>=k)
    {
        cout<<"YES\n";
        for (int i=1;i<k;++i)
            cout<<"1 ";
        cout<<n-(k-1)<<"\n";
        return;
    }
    if (n%2==0&&n-(2*k)>=0)
    {
        cout<<"YES\n";
        for (int i=1;i<k;++i)
            cout<<"2 ";
        cout<<n-((k-1)*(2))<<"\n";
        return;
    }
    if (n%2==0&&k%2==0)
    {
        cout<<"YES\n";
        for (int i=1;i<k;++i)
            cout<<"1 ";
        cout<<n-(k-1)<<"\n";
        return;
    }
    cout<<"NO\n";
    return;
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