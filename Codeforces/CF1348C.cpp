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

int prefix[27];

void solve()
{
    int n,k;
    cin>>n>>k;
    string s,ans="";
    cin>>s;
    sort(s.begin(), s.end());
    if (k==1)
    {
        cout<<s<<"\n";
        return;
    }
    if (s[k-1]!=s[0])
    {
        cout<<s[k-1]<<"\n";
        return;
    }
    if (s[0]==s[n-1])
    {
        for (int i=0;i<n;i+=k)
            cout<<s[i];
        cout<<"\n";
        return;
    }
    if (s[k]==s[n-1])
    {
        for (int i=0;i<n;i+=k)
            cout<<s[i];
        cout<<"\n";
        return;
    }
    for (int i=k-1;i<n;++i)
    {
        cout<<s[i];
    }
    cout<<"\n";
    return;
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