#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mod = 1e9+7;
int n,ans=0;
string s;

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res;
}

void equal(string& t)
{
    for (int i=0;i<n;++i)
        if (!(s[i]=='?'||s[i]==t[i]))
            return;
    ++ans;
}

void split(string& t)
{
    string u="",cur="";
    for (int i=0;i+1<n;++i)
    {
        cur+=t[i];
        if (t[i]==t[i+1])
            while (sz(cur))
            {
                u+=cur.back();
                cur.pop_back();
            }
    }
    cur+=t[n-1];
    if (sz(cur)==n)
        equal(cur);
    else
    {
        while (sz(cur))
        {
            u+=cur.back();
            cur.pop_back();
        }
        equal(u);
    }
}

void rec(string t)
{
    if (sz(t)==n)
    {
        split(t);
        return;
    }
    rec(t+"A");
    rec(t+"G");
    rec(t+"C");
    rec(t+"T");
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>s;
    n=sz(s);
    if (n<=21)
    {
        rec("");
        cout<<ans;
        return 0;
    }
    for (auto i : s)
        if (i=='?')
            --n;
    if (n==0)
    {
        cout<<binpow(4,sz(s));
        return 0;
    }
    return 0;
}