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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    ll a[n+1],k;
    k=n-1;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    if (n==1)
    {
        cout<<"1 1\n"<<-a[1]<<"\n1 1\n0\n1 1\n0\n";
        return 0;
    }
    cout<<"1 1\n"<<-a[1]<<"\n";
    cout<<"2 "<<n<<"\n";
    a[1]=0;
    for (int i=2;i<=n;++i)
    {
        cout<<k*(((a[i]%n)+n)%n)<<" ";
        a[i]+=k*(((a[i]%n)+n)%n);
    }
    cout<<"\n1 "<<n<<"\n";
    for (int i=1;i<=n;++i)
        cout<<-a[i]<<" ";
    return 0;
}