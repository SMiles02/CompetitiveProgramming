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

void solve()
{
    int n;
    string s;
    cin>>s;
    n=sz(s);
    vector<int> v;
    for (int i=0;i<n;++i)
    {
        if (s[i]=='1')
        {
            v.push_back(i);
        }
    }
    if (!sz(v))
    {
        cout<<"0\n";
        return;
    }
    int ans=0;
    for (int i=v[0];i<v.back();++i)
    {
        if (s[i]=='0')
        {
            ++ans;
        }
    }
    cout<<ans<<"\n";return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}