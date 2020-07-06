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

int cost()
{
    int ans=0;
    string s;
    cin>>s;
    for (auto c : s)
        ans+=(c-'0');
    return ans;
}

int check()
{
    int a,b;
    a=cost();
    b=cost();
    if (a>b)
        return 0;
    if (a<b)
        return 1;
    return 2;
}

void solve()
{
    int n,a=0,b=0,x;
    cin>>n;
    while (n--)
    {
        x=check();
        if (x==2)
        {
            ++a;++b;
        }
        else if (x==1)
            ++b;
        else
            ++a;
    }
    if (a>b)
        cout<<"0 ";
    else if (a<b)
        cout<<"1 ";
    else
        cout<<"2 ";
    cout<<max(a,b)<<"\n";
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