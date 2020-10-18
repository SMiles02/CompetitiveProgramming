#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
        return res * a;
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
    if (s[3]-'0'>5)
        s[3]='5';
    if (n==12)
    {
        if (12<(s[0]-'0')*10+(s[1]-'0'))
        {
            if (s[1]=='0')
                s[0]='1';
            else
                s[0]='0';
        }
        if (0==(s[0]-'0')*10+(s[1]-'0'))
            s[0]='1';
    }
    else
    {
        if (23<(s[0]-'0')*10+(s[1]-'0'))
            s[0]='1';
    }
    cout<<s;
    return 0;
}