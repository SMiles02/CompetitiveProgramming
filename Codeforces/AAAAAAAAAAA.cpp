#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,k;
    cin>>n>>m;
    deque<int> a[m+1];
    for (int i=1;i<=m;++i)
    {
        cin>>x;
        for (int j=0;j<x;++j)
        {
            cin>>k;
            a[i].push_back(k);
        }
    }
    vector<pii> ans;
    for (int i=1;i<m;++i)
    {
        while (!(a[i].empty()))
        {
            k=a[i].front();
            a[i].pop_front();
            a[m].push_front(k);
            ans.push_back({i,m});
            //cout<<i<<" "<<m<<"!\n";
        }
    }
    while (!(a[m].empty()))
    {
        k=a[m].front();
        a[m].pop_front();
        if (k==1||k==m)
        {
            a[1].push_front(k);
            ans.push_back({m,1});
        }
        else
        {
            a[k].push_front(k);
            ans.push_back({m,k});
        }
    }
    while (!(a[1].empty()))
    {
        k=a[1].front();
        a[1].pop_front();
        if (k==1)
            x=2;
        else
            x=m;
        a[x].push_front(k);
        ans.push_back({1,x});
    }
    while (sz(a[2])&&a[2].front()==1)
    {
        a[2].pop_front();
        ans.push_back({2,1});
    }
    cout<<ans.size()<<"\n";
    for (pii i : ans)
        cout<<i.f<<" "<<i.s<<"\n";
    return 0;
}