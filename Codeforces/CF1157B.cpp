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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    string s;
    cin>>n;
    cin>>s;
    int a[10];
    for (int i=1;i<10;++i)
    {
        cin>>a[i];
    }
    int done=0,started=0;
    for (int i=0;i<n;++i)
    {
        if (!started)
        {
            if ((s[i]-'0')>=a[s[i]-'0'])
            {
                cout<<s[i];
            }
            else
            {
                started=1;
                cout<<a[s[i]-'0'];
            }
        }
        else if (done)
        {
            cout<<s[i];
        }
        else
        {
            if ((s[i]-'0')<=a[s[i]-'0'])
            {
                cout<<a[s[i]-'0'];
            }
            else
            {
                done=1;
                cout<<s[i];
            }
        }
    }
    return 0;
}