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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>k;
    char maxi='a';
    string s;
    cin>>s;
    n=sz(s);
    map<char,int> m;
    set<char> se;
    for (int i=0;i<n;++i)
    {
        ++m[s[i]];
        if (s[i]!='?'&&s[i]-'a'>maxi-'a')
            maxi=s[i];
    }
    for (char c='a';c<=('a'+k-1);++c)
        if (!m[c])
            se.insert(c);
    for (int i=0;i<n;++i)
    {
        if (s[i]!='?'&&s[n-i-1]!='?')
        {
            if (s[i]!=s[n-i-1])
            {
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
        else if (s[i]=='?')
        {
            s[i]=s[n-i-1];
        }
    }
    int x=0;
    if (n%2)
    {
        for (int i=0;i<=n/2;++i)
            if (s[i]=='?')
                ++x;
    }
    else
    {
        for (int i=0;i<n/2;++i)
            if (s[i]=='?')
                ++x;
    }
    for (int i=0;i<n;++i)
    {
        if (s[i]=='?'&&x>sz(se))
        {
            s[i]='a';
            s[n-i-1]='a';
            --x;
        }
        else if (s[i]=='?')
        {
            s[i]=*(se.begin());
            s[n-i-1]=*(se.begin());
            se.erase((se.begin()));
            --x;
        }
    }
    if (sz(se))
        cout<<"IMPOSSIBLE";
    else
        cout<<s;
    return 0;
}