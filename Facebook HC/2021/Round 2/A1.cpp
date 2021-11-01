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

const int NM = 1e6;
bitset<NM> used;

int solve()
{
    int n,m,ans=0,x;
    cin>>n>>m;
    multiset<array<int,2>> a,b,c,d;
    vector<int> v(m);
    for (int i=0;i<m;++i)
    {
        cin>>x;
        used[i]=0;
        a.insert({x,i});
    }
    while (n--)
    {
        for (int i=0;i<m;++i)
        {
            cin>>v[i];
            if (b.lower_bound({v[i],0})!=b.end()&&(*(b.lower_bound({v[i],0})))[0]==v[i])
            {
                d.insert(*b.lower_bound({v[i],0}));
                b.erase(b.lower_bound({v[i],0}));
                v[i]=0;
            }
            else if (a.lower_bound({v[i],0})!=a.end()&&(*(a.lower_bound({v[i],0})))[0]==v[i])
            {
                c.insert(*a.lower_bound({v[i],0}));
                a.erase(a.lower_bound({v[i],0}));
                v[i]=0;
            }
        }
        for (int i=0;i<m;++i)
            if (v[i])
            {
                if (!a.empty())
                {
                    d.insert({v[i],(*(a.begin()))[1]});
                    a.erase(a.begin());
                }
                else
                {
                    d.insert({v[i],(*(b.begin()))[1]});
                    b.erase(b.begin());
                    ++ans;
                }
            }
        swap(a,c);
        swap(b,d);
        c.clear();
        d.clear();
    }
    return ans;
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    for (int i=1;i<=t;++i)
        cout<<"Case #"<<i<<": "<<solve()<<"\n";
    return 0;
}