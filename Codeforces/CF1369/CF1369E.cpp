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

vector<int> v[100005];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    int w[n];
    int a[n];
    pair<int,int> xy[m];
    for (int i=1;i<=n;++i)
    {
        cin>>w[i];
        a[i]=w[i];
    }
    for (int i=1;i<=m;++i)
    {
        cin>>xy[i].first>>xy[i].second;
        v[xy[i].first].push_back(i);
        v[xy[i].second].push_back(i);
        --a[xy[i].first];
        --a[xy[i].second];
    }
    pair<int,int> p[n];
    for (int i=0;i<n;++i)
    {
        p[i].first=a[i];
        p[i].second=i+1;
    }
    sort(p,p+n);
    map<int,bool> dict;
    vector<int> ans;
    for (int i=1;i<=n;++i)
    {
        for (int j : v[i])
        {
            if (dict[j])
                continue;
            dict[j]=1;
            ans.push_back(j);
        }
    }
    for (int i : ans)
    {
        if (w[xy[i].first]<1&&w[xy[i].second]<1)
        {
            cout<<"DEAD\n";
            return 0;
        }
        --w[xy[i].first];
        --w[xy[i].second];
    }
    cout<<"ALIVE\n";
    for (int i : ans)
        cout<<i<<" ";
    return 0;
}