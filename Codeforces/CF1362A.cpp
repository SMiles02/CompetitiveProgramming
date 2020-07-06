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
    ll a,b,x=0;
    cin>>a>>b;
    while (a*8<=b)
    {
        ++x;
        a*=8;
    }
    while (a*4<=b)
    {
        ++x;
        a*=4;
    }
    while (a*2<=b)
    {
        ++x;
        a*=2;
    }
    while (a%8==0&&a/8>=b)
    {
        ++x;
        a/=8;
    }
    while (a%4==0&&a/4>=b)
    {
        ++x;
        a/=4;
    }
    while (a%2==0&&a/2>=b)
    {
        ++x;
        a/=2;
    }
    if (a!=b)
    {
        cout<<"-1\n";
        return;
    }
    cout<<x<<"\n";
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