#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

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
    cin>>n;
    vector<string> s(n),t(n),u(n);
    for (int i=0;i<n;++i)
    {
        cin>>s[i];
        t[i]=s[i];
    }
    for (int i=0;i<n;++i)
        cin>>u[i];
    for (int i=0;i<n;++i)
        if (s[i][0]!=u[i][0])
            for (int j=0;j<n;++j)
            {
                if (s[i][j]=='1')
                    s[i][j]='0';
                else
                    s[i][j]='1';
            }
    for (int i=0;i<n;++i)
    {
        if (t[i][0]=='0')
            t[i][0]='1';
        else
            t[i][0]='0';
    }
    for (int i=0;i<n;++i)
        if (t[i][0]!=u[i][0])
            for (int j=0;j<n;++j)
            {
                if (t[i][j]=='1')
                    t[i][j]='0';
                else
                    t[i][j]='1';
            }
    for (int j=0;j<n;++j)
        if (s[0][j]!=u[0][j])
            for (int i=0;i<n;++i)
            {
                if (s[i][j]=='1')
                    s[i][j]='0';
                else
                    s[i][j]='1';
            }
    for (int j=0;j<n;++j)
        if (t[0][j]!=u[0][j])
            for (int i=0;i<n;++i)
            {
                if (t[i][j]=='1')
                    t[i][j]='0';
                else
                    t[i][j]='1';
            }
    /**
    for (int i=0;i<n;++i)
        cout<<s[i]<<"\n";
    cout<<"\n";
    for (int i=0;i<n;++i)
        cout<<t[i]<<"\n";
    cout<<"\n";
    **/
    if (s==u||t==u)
        cout<<"YES\n";
    else
        cout<<"NO\n";
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