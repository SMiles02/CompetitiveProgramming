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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,t,a,b,c=0;
    cin>>n;
    string s;
    cin>>s;
    cin>>q;
    while (q--)
    {
        cin>>t>>a>>b;
        --a;--b;
        if (t==2)
            c^=1;
        else if (c)
        {
            if (a<n)
                a+=n;
            else
                a-=n;
            if (b<n)
                b+=n;
            else
                b-=n;
            swap(s[a],s[b]);
        }
        else
            swap(s[a],s[b]);
    }
    if (c)
    {
        for (int i=n;i<2*n;++i)
            cout<<s[i];
        for (int i=0;i<n;++i)
            cout<<s[i];
    }
    else
        cout<<s;
    return 0;
}