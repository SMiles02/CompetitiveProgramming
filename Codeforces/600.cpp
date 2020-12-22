#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
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
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x,y,m,p;
    cin>>n>>k;
    int a[n+1];
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        pq.push({a[i],i});
    }
    while (!pq.empty()&&k)
    {
        x=pq.top().second;
        y=pq.top().first;
        pq.pop();
        if (a[x]!=y)
            continue;
        if (y<0)
            break;
        --k;
        a[x]=-1;
        cout<<"1 "<<x<<endl;
        cin>>m;
        for (int i=0;i<m;++i)
        {
            cin>>p;
            a[p]=-1;
        }
    }
    cout<<3<<endl;
    return 0;
}