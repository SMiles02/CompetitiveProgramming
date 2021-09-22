  
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

const int N = 2100;
int a[N], b[N];

void flip(int x)
{
    for (int i=1;i<=x;++i)
        b[i]=a[i];
    for (int i=1;i<=x;++i)
        a[i]=b[x-i+1];
}

void solve()
{
    int n, x;
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    vector<int> v;
    for (int i=n;i>=1;--i)
    {
        if (i==a[i])
            continue;
        if (i&1)
        {
            x=6969;
            for (int j=1;j<=i;++j)
                if (a[j]==i)
                    x=j;
            if ((x&1)==0)
            {
                cout<<"-1\n";
                return;
            }
            flip(x);
            flip(i);
            v.push_back(x);
            v.push_back(i);
        }
        else
        {
            cout<<"-1\n";
            return;
        }
    }
    cout<<sz(v)<<"\n";
    for (int i : v)
        cout<<i<<" ";
    cout<<"\n";
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