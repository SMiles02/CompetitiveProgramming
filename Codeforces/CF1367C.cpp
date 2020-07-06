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

int to[1000000];
int fro[1000000];

void solve()
{
    int n,k,ans=0;
    string s;
    cin>>n>>k;
    cin>>s;
    to[0]=1000000;
    fro[n-1]=1000000;
    for (int i=n-2;i>=0;--i)
    {
        fro[i]=fro[i+1]+1;
        if (s[i+1]=='1')
            fro[i]=1;
    }
    for (int i=0;i<n;++i)
    {
        if (i==0)
            to[i]=1000000;
        else if (s[i-1]=='1')
            to[i]=1;
        else
            to[i]=to[i-1]+1;
        if (s[i]=='0'&&to[i]>k&&fro[i]>k)
        {
            ++ans;
            to[i]=0;
        }
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