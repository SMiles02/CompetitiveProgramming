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

int a[50][50];

void solve()
{
    int n,m,r=0,c=0,x;
    cin>>n>>m;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            cin>>a[i][j];
    for (int i=0;i<n;++i)
    {
        x=1;
        for (int j=0;j<m&&x;++j)
            if (a[i][j])
                x=0;
        if (x)
            ++r;
    }
    for (int j=0;j<m;++j)
    {
        x=1;
        for (int i=0;i<n&&x;++i)
            if (a[i][j])
                x=0;
        if (x)
            ++c;
    }
    if (min(r,c)%2)
        cout<<"Ashish\n";
    else
        cout<<"Vivek\n";
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