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

void solve()
{
    int n,ans,cur,l;
    string s;
    cin>>s;
    n=sz(s);
    ans=n-2;
    int odd[10],even[10];
    for (int i=0;i<10;++i)
    {
        odd[i]=0;
        even[i]=0;
    }
    for (int i=0;i<n;i+=2)
        ++even[s[i]-'0'];
    for (int i=1;i<n;i+=2)
        ++odd[s[i]-'0'];
    for (int i=0;i<10;++i)
        ans=min(ans,n-odd[i]-even[i]);
    for (int i=0;i<10;++i)
        for (int j=0;j<10;++j)
        {
            cur=0;l=0;
            for (int k=0;k<n;++k)
            {
                if (l&1)
                {
                    if (s[k]-'0'==j)
                        ++l;
                    else
                        ++cur;
                }
                else
                {
                    if (s[k]-'0'==i)
                        ++l;
                    else
                        ++cur;
                }
            }
            if (l&1&&(i!=j))
                ++cur;
            //cout<<i<<" "<<j<<": "<<cur<<"\n";
            ans=min(ans,cur);
        }
    cout<<ans<<"\n";
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