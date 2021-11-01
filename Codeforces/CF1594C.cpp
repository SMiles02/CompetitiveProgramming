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

const int N = 3e5+1;
int a[N];
vector<int> f[N];

void solve()
{
    int n,ct=0;
    char c;
    string s;
    cin>>n;
    cin>>c;
    cin>>s;
    for (int i=1;i<=n;++i)
        a[i]=0;
    for (int i=0;i<n;++i)
        if (s[i]!=c)
        {
            ++ct;
            for (int j : f[i+1])
                ++a[j];
        }
    if (ct==0)
    {
        cout<<"0\n";
        return;
    }
    for (int i=1;i<=n;++i)
        if (a[i]==0)
        {
            cout<<"1\n"<<i<<"\n";
            return;
        }
    cout<<"2\n"<<n-1<<" "<<n<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=1;i<N;++i)
        for (int j=i;j<N;j+=i)
            f[j].push_back(i);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}