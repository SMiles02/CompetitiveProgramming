#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

void solve()
{
    string s,t,u="",v="";
    cin>>s;
    cin>>t;
    int n=sz(s),m=sz(t),k;
    k=(n*m)/gcd(n,m);
    while (sz(u)<k)
        u+=s;
    while (sz(v)<k)
        v+=t;
    if (u==v)
        cout<<u<<"\n";
    else
        cout<<"-1\n";
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