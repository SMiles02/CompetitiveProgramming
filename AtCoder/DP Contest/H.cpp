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
    int n,m;
    cin>>n>>m;
    string s[n];
    for (int i=0;i<n;++i)
    {
        cin>>s[i];
    }
    ll a[n][m];
    a[0][0]=1;
    for (int j=1;j<m;++j)
    {
        if (s[0][j]=='#')
        {
            a[0][j]=0;
        }
        else
        {
            a[0][j]=a[0][j-1];
        }
    }
    for (int i=1;i<n;++i)
    {
        if (s[i][0]=='#')
        {
            a[i][0]=0;
        }
        else
        {
            a[i][0]=a[i-1][0];
        }
    }
    for (int i=1;i<n;++i)
    {
        for (int j=1;j<m;++j)
        {
            if (s[i][j]=='#')
            {
                a[i][j]=0;
            }
            else
            {
                a[i][j]=a[i-1][j]+a[i][j-1];
                a[i][j]%=1000000007;
            }
        }
    }
    cout<<a[n-1][m-1];
    return 0;
}