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

void solve()
{
    int n,diff=0,same=0,f=0,ans=0;
    cin>>n;
    int a[n],b[n+1],c[n+1];
    for (int i=0;i<=n;++i)
    {
        b[i]=0;
        c[i]=0;
    }
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        ++b[a[i]];
    }
    for (int i=1;i<=n;++i)
        if ((n+1)/2<b[i])
        {
            cout<<"-1\n";
            return;
        }
    for (int i=1;i<n;++i)
        if (a[i]==a[i-1])
        {
            if (a[i-1]==a[f])
            {
                ++c[a[f]];
                ++same;
            }
            else
                ++diff;
            f=i;
            ++ans;
        }
    if (a[n-1]==a[f])
    {
        ++c[a[f]];
        ++same;
    }
    else
        ++diff;
    priority_queue<pair<int,int>> pq;
    for (int i=1;i<=n;++i)
        if (c[i])
            pq.push({c[i],i});
    pair<int,int> p;
    while (diff&&!pq.empty())
    {
        p=pq.top();
        pq.pop();
        if (p.first==0)
        {
            cout<<ans<<"\n";
            return;
        }
        --p.first;
        --diff;
        --same;
        pq.push(p);
    }
    if (pq.empty())
    {
        cout<<ans<<"\n";
        return;
    }
    p=pq.top();
    //cout<<p.first<<"\n";
    //cout<<same<<"\n";
    if (p.first*2<=same)
    {
        cout<<ans<<"\n";
        return;
    }
    p.first-=(same-p.first);
    cout<<ans+max(0,p.first-1)<<"\n";
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