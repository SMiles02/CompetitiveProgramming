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

int a[300][300];

void solve()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            cin>>a[i][j];
    if (a[0][0]>2)
    {
        cout<<"NO\n";
        return;
    }
    else
        a[0][0]=2;
    if (a[0][m-1]>2)
    {
        cout<<"NO\n";
        return;
    }
    else
        a[0][m-1]=2;
    if (a[n-1][0]>2)
    {
        cout<<"NO\n";
        return;
    }
    else
        a[n-1][0]=2;
    if (a[n-1][m-1]>2)
    {
        cout<<"NO\n";
        return;
    }
    else
        a[n-1][m-1]=2;
    for (int i : {0,n-1})
        for (int j=1;j<m-1;++j)
        {
            if (a[i][j]>3)
            {
                cout<<"NO\n";
                return;
            }
            a[i][j]=3;
        }
    for (int i=1;i<n-1;++i)
        for (int j : {0,m-1})
        {
            if (a[i][j]>3)
            {
                cout<<"NO\n";
                return;
            }
            a[i][j]=3;
        }
    for (int i=1;i<n-1;++i)
        for (int j=1;j<m-1;++j)
        {
            if (a[i][j]>4)
            {
                cout<<"NO\n";
                return;
            }
            a[i][j]=4;
        }
    cout<<"YES\n";
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<m;++j)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
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