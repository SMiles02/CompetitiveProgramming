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
vector<int> s[N], e[N];
multiset<int> inUse;
multiset<int,greater<int>> pot;

void solve()
{
    int n,d,k,x,y,z;
    ll cur=0,ans=0;
    cin>>d>>n>>k;
    while (n--)
    {
        cin>>x>>y>>z;
        s[y].push_back(x);
        e[z].push_back(x);
    }
    for (int i=1;i<=d;++i)
    {
        while (!s[i].empty())
        {
            x=s[i].back();
            s[i].pop_back();
            if (sz(inUse)<k)
            {
                cur+=x;
                inUse.insert(x);
            }
            else if (x>*inUse.begin())
            {
                y=*inUse.begin();
                inUse.erase(inUse.begin());
                inUse.insert(x);
                pot.insert(y);
                cur+=x-y;
            }
            else
                pot.insert(x);
        }
        ans=max(ans,cur);
        while (!e[i].empty())
        {
            x=e[i].back();
            e[i].pop_back();
            y=sz(pot)+sz(inUse);
            if (pot.find(x)!=pot.end())
                pot.erase(pot.find(x));
            else
            {
                inUse.erase(inUse.find(x));
                cur-=x;
            }
        }
        while (sz(inUse)<k&&!pot.empty())
        {
            cur+=*pot.begin();
            inUse.insert(*pot.begin());
            pot.erase(pot.begin());
        }
    }
    cout<<ans<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    for (int i=1;i<=t;++i)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}