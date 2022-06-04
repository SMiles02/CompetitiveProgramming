//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
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

int n;
string s;

bool is_prime(int k)
{
    if (k==1)
        return 0;
    for (int j=2;j*j<=k;++j)
        if (k%j==0)
            return 0;
    return 1;
}

bool rec(ll cur, int curL, int start, int tot)
{
    if (curL==tot)
    {
        if (!is_prime(cur))
        {
            cout<<tot<<"\n"<<cur<<"\n";
            return 1;
        }
        return 0;
    }
    for (int i=start;i<n;++i)
        if (rec(cur*10+(s[i]-'0'),curL+1,i+1,tot))
            return 1;
    return 0;
}

void solve()
{
    int cur;
    cin>>n;
    cin>>s;
    for (int j=1;j<n;++j)
        if (rec(0,0,0,j))
            return;
    cout<<n<<"\n"<<s<<"\n";
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