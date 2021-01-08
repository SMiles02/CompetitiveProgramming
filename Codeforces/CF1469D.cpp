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
    int n,k;
    cin>>n;
    array<int,2> a;
    vector<array<int,2>> ans;
    priority_queue<array<int,2>> pq;
    k=n;
    pq.push({n,n});
    pq.push({2,2});
    for (int i=n-1;i>2;--i)
    {
        if (i==(k+15)/16)
        {
            pq.push({i,i});
            k=i;
        }
        else
            ans.push_back({i,n});
    }
    while (sz(pq)>1)
    {
        a=pq.top();pq.pop();
        ans.push_back({a[1],pq.top()[1]});
        a[0]=(a[0]+pq.top()[0]-1)/pq.top()[0];
        if (a[0]>1)
            pq.push(a);
    }
    cout<<sz(ans)<<"\n";
    for (auto i : ans)
        cout<<i[0]<<" "<<i[1]<<"\n";
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