#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll binpow(ll a, ll b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
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

int a[100][2];

void solve()
{
    int n,x,m,l,r,ans=0;
    cin>>n>>x>>m;
    vector<pair<int,int>> v;
    v.push_back({x,x});
    for (int i=0;i<m;++i)
    {
        cin>>l>>r;
        for (auto i : v)
        {
            if (r<i.first||i.second<l)
                continue;
            v.push_back({l,r});
            break;
        }
    }
    x=0;
    sort(v.begin(), v.end());
    for (auto i : v)
    {
        ans+=max(0,i.second-max(i.first,x+1)+1);
        x=max(x,i.second);
    }
    cout<<ans<<"\n";
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