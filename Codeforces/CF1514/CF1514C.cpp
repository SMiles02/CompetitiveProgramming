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

void solve(int n)
{
    if (n<5)
    {
        cout<<"1\n1\n";
        return;
    }
    vector<int> v,w,x;
    for (int i=1;i<n;++i)
        if (gcd(i,n)==1)
            v.push_back(i);
    w.resize(sz(v));
    x.resize(sz(v));
    w[0]=v[0];
    x[sz(v)-1]=v[sz(v)-1];
    for (int i=1;i<sz(v);++i)
        w[i]=(1LL*w[i-1]*v[i])%n;
    for (int i=sz(v)-2;i>=0;--i)
        x[i]=(1LL*x[i+1]*v[i])%n;
    if (w[sz(v)-1]==1)
    {
        cout<<sz(v)<<"\n";
        for (int i=0;i<sz(v);++i)
            cout<<v[i]<<" ";
        cout<<"\n";
        return;
    }
    if (w[sz(v)-2]==1)
    {
        cout<<sz(v)-1<<"\n";
        for (int i=0;i+1<sz(v);++i)
            cout<<v[i]<<" ";
        cout<<"\n";
        return;
    }
    for (int i=1;i+1<sz(v);++i)
        if ((1LL*w[i-1]*x[i+1])%n==1)
        {
            cout<<sz(v)-1<<"\n";
            for (int j=0;j<i;++j)
                cout<<v[j]<<" ";
            for (int j=i+1;j<sz(v);++j)
                cout<<v[j]<<" ";
            cout<<"\n";
            return;
        }
    cerr<<n<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    solve(n);
    return 0;
}