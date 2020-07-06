#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k=0;
    ll ans=1;
    vector<ll> v;
    string s;
    cin>>s;
    map<char,int> m;
    n=sz(s);
    for (int i=0;i<n;++i)
    {
        ++m[s[i]];
        k+=(s[i]-'0');
    }
    for (int i=1;i<10;++i)
    {
        if (m[i+'0']==n)
        {
            cout<<s;
            return 0;
        }
        else if (m[i+'0']+m['0']==n)
        {
            v.push_back(i);
        }
    }
    if (!(k%9))
    {
        v.push_back(9);
    }
    if (m['8']+m['0']==n)
    {
        v.push_back(8);
    }
    if (m['4']+m['8']+m['0']==n)
    {
        v.push_back(4);
    }
    if (!(k%3))
    {
        v.push_back(3);
    }
    if (m['0']+m['2']+m['4']+m['6']+m['8']==n)
    {
        v.push_back(2);
    }
    if (m['0']+m['5']==n)
    {
        v.push_back(5);
    }
    for (int i=0;i<sz(v);++i)
    {
        //cout<<v[i]<<" !\n";
        ans=ans*((v[i])/(gcd(ans,v[i])));
    }    
    cout<<ans;
    return 0;
}