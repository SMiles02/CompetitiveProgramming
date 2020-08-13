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
    int n,x;
    cin>>n;
    string s[n];
    for (int i=0;i<n;++i)
        cin>>s[i];
    bool eq;
    for (int i=n-2;i>=0;--i)
    {
        eq=1;
        for (int j=0;j<min(sz(s[i]),sz(s[i+1]));++j)
            if (s[i][j]!=s[i+1][j])
            {
                eq=0;
                break;
            }
        if (eq)
        {
            while (sz(s[i])>sz(s[i+1]))
                s[i].pop_back();
            //cout<<i<<"!!!";
            continue;
        }
        for (int j=0;j<sz(s[i]);++j)
        {
            if (s[i][j]<s[i+1][j])
            {
                x=sz(s[i]);
                break;
            }
            if (s[i][j]>s[i+1][j])
            {
                x=j;
                break;
            }
        }
        //cout<<s[i]<<" "<<x<<"\n";
        while (sz(s[i])>x)
            s[i].pop_back();
    }
    for (int i=0;i<n;++i)
        cout<<s[i]<<"\n";
    return 0;
}