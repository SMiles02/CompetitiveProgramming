#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int k;

int su(string s)
{
    int x=0;
    for (auto i : s)
        x+=(i-'0');
    return x;
}

string calc(string s, int x)
{
    bool c=1;
    for (int i=x+1;i<k;++i)
        s[i]='0';
    for (int i=x;i+1;--i)
    {
        if (c)
        {
            if (s[i]=='9')
                s[i]='0';
            else
            {
                ++s[i];
                c=0;
            }
        }
    }
    return s;
}

ll toNum(string s)
{
    ll x=0;
    for (auto i : s)
    {
        x*=10;
        x+=(i-'0');
    }
    return x;
}

void solve()
{
    ll n;
    int s,l,r,m;
    cin>>n>>s;
    string t=to_string(n);
    if (su(t)<=s)
    {
        cout<<"0\n";
        return;
    }
    t="0"+t;
    k=sz(t);
    l=0;r=k-1;
    while (l<r)
    {
        m=l+(r-l)/2+1;
        if (su(calc(t,m))<=s)
            l=m;
        else
            r=m-1;
    }
    //cout<<toNum(calc(t,l))<<"\n";
    cout<<toNum(calc(t,l))-n<<"\n";
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