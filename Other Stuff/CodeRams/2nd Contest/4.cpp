#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

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

bool allNine(string& s)
{
    for (auto i : s)
        if (i!='9')
            return 0;
    return 1;
}

ll toInt(string s)
{
    ll r=0;
    for (auto i : s)
    {
        r*=10;
        r+=(i-'0');
    }
    return r;
}

string iCantCode = "0123456789";

string toStr(ll k)
{
    string s="",t="";
    while (k)
    {
        s+=iCantCode[k%10];
        k/=10;
    }
    while (sz(s))
    {
        t+=s.back();
        s.pop_back();
    }
    return t;
}

bool isMagic(string s, int n)
{
    for (int i=n;i<2*n;++i)
        if (s[i]!=s[i-n])
            return 0;
    return 1;
}

string firstHalf(string s, int n)
{
    string t="";
    for (int i=0;i<n;++i)
        t+=s[i];
    return t;
}

string zeroes(int k)
{
    string s="";
    while (k--)
        s+='0';
    return s;
}

string concat(string s, string t)
{
    s+=t;
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s,t;
    cin>>s;
    int n;
    ll ans=0;
    while (1)
    {
        //cout<<s<<"\n";
        n=sz(s);
        if (n&1&&allNine(s))
        {
            cout<<ans;
            return 0;
        }
        if ((n&1)==0&&isMagic(s,n/2))
        {
            ++ans;
            s=firstHalf(s,n/2);
        }
        else if (n&1)
        {
            cout<<ans+binpow(10,n)-1-toInt(s);
            return 0;
        }
        else if (toInt(s)<toInt(concat(firstHalf(s,n/2),firstHalf(s,n/2))))
        {
            ans+=toInt(concat(firstHalf(s,n/2),firstHalf(s,n/2)))-toInt(s)+1;
            s=firstHalf(s,n/2);
        }
        else
        {
            ans+=toInt(concat(toStr(toInt(firstHalf(s,n/2))+1),zeroes(n/2)))-toInt(s);
            s=concat(firstHalf(s,n/2),zeroes(n/2));
        }
    }
    return 0;
}