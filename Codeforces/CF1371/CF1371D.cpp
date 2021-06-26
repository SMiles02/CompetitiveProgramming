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

int sq(int x)
{
    return x*x;
}

bool a[300][300];

void solve()
{
    int n,k,maxR=0,minR=300,maxC=0,minC=300,cur;
    cin>>n>>k;
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            a[i][j]=0;
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            if (k)
            {
                --k;
                a[(i+j)%n][j]=1;
            }
    for (int i=0;i<n;++i)
    {
        cur=0;
        for (int j=0;j<n;++j)
            cur+=a[i][j];
        minR=min(minR,cur);
        maxR=max(maxR,cur);
    }
    for (int j=0;j<n;++j)
    {
        cur=0;
        for (int i=0;i<n;++i)
            cur+=a[i][j];
        minC=min(minC,cur);
        maxC=max(maxC,cur);
    }
    cout<<sq(maxC-minC)+sq(maxR-minR)<<"\n";
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
            cout<<a[i][j];
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