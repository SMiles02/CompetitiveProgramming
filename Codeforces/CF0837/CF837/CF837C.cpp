#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
        return 1;
    int res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
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
    int n,a,b,x,y,ans=0;
    cin>>n>>a>>b;
    vector<pair<int,int>> v;
    for (int i=0;i<n;++i)
    {
        cin>>x>>y;
        v.push_back({x,y});
    }
    for (int i=0;i<n;++i)
    {
        for (int j=i+1;j<n;++j)
        {
            if (((v[i].first+v[j].first<=a)&&(max(v[i].second,v[j].second)<=b))  ||  ((v[i].first+v[j].second<=a)&&(max(v[i].second,v[j].first)<=b)) || ((v[i].second+v[j].first<=a)&&(max(v[i].first,v[j].second)<=b))  ||  ((v[i].second+v[j].second<=a)&&(max(v[i].first,v[j].first)<=b)))
            {
                ans=max(ans,v[i].first*v[i].second+v[j].first*v[j].second);
            }
        }
    }
    cout<<ans;
    return 0;
}