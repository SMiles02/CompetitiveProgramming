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

vector<int> locations[100000+6];

void solve()
{
    int n,x,y,z,c,m;
    cin>>n>>x>>y;
    int a[n];
    int ans[n];
    for (int i=1;i<n+2;++i)
        locations[i].clear();
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        locations[a[i]].push_back(i);
    }
    priority_queue<pair<int,int>> q;
    pair<int,int> p;
    for (int i=1;i<n+2;++i)
    {
        if (sz(locations[i]))
            q.push({sz(locations[i]),i});
        else
            z=i;
    }
    for (int i=0;i<x;++i)
    {
        p=q.top();
        q.pop();
        ans[locations[p.second].back()]=p.second;
        locations[p.second].pop_back();
        --p.first;
        if (p.first)
            q.push(p);
    }
    c=n-y;
    vector<pair<int,int>> temp;
    vector<pair<int,int>> newTemp;
    while (sz(q))
    {
        for (int i : locations[q.top().second])
            temp.push_back({i,q.top().second});
        q.pop();
    }
    m=sz(temp);
    for (auto i : temp)
        newTemp.push_back(i);
    for (int i=0;i<m&&c;++i)
    {
        newTemp.push_back(temp[i]);
        if (temp[(i-m/2+m)%m].second==temp[i].second)
        {
            newTemp[i].second=z;
            --c;
        }
    }
    for (int i=0;c;++i)
        if (newTemp[i].second!=z)
        {
            newTemp[i].second=z;
            --c;
        }
    for (int i=0;i<m;++i)
    {
        ans[newTemp[i].first]=newTemp[(i+(m/2))%m].second;
        if (ans[newTemp[i].first]==a[newTemp[i].first])
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    for (int i=0;i<n;++i)
        cout<<ans[i]<<" ";
    cout<<"\n";
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