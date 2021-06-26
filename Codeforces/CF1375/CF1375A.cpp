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

int a[100];
int b[100];
int c[100];

void solve()
{
    int n,pos=0,neg=0;
    cin>>n;
    vector<int> g1;
    vector<int> g2;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        if (a[i]<0)
            a[i]=-a[i];
    }
    for (int i=0;i<n;++i)
        b[i]=0;
    for (int i=0;i<n;++i)
        c[i]=0;
    for (int i=0;i<n-1;++i)
        if (a[i]>=a[i+1])
            ++b[i];
    for (int i=1;i<n;++i)
        if (a[i]>a[i-1])
            ++c[i];
    for (int i=0;i<n;++i)
        if (b[i]^c[i])
        {
            if (b[i])
                g1.push_back(i);
            else
                g2.push_back(i);
        }
    for (int i : g1)
    {
        if (pos>neg)
        {
            a[i]=-a[i];
            ++neg;
        }
        else
            ++pos;
    }
    for (int i : g2)
    {
        if (pos>neg)
            ++neg;
        else
        {
            a[i]=-a[i];
            ++pos;
        }
    }
    for (int i=0;i<n;++i)
        cout<<a[i]<<" ";
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