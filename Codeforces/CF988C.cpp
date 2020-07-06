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
    int t,n,su,k,d;
    vector<pair<int,pair<int,int>>> p;
    vector<pair<int,int>> v;
    map<int,int> m;
    cin>>t;
    for (int z=1;z<=t;++z)
    {
        cin>>n;
        su=0;
        for (int i=1;i<=n;++i)
        {
            cin>>k;
            su+=k;
            if (!m[k])
            {
                ++m[k];
                v.push_back(make_pair(k,i));
            }
        }
        d=sz(v);
        for (int i=0;i<d;++i)
        {
            p.push_back(make_pair(su-v[i].first,make_pair(z,v[i].second)));
        }
        m.clear();
        v.clear();
    }
    sort(p.begin(), p.end());
    d=sz(p);
    for (int i=0;i<d-1;++i)
    {
        if (p[i].first==p[i+1].first)
        {
            cout<<"YES\n";
            cout<<p[i].second.first<<" "<<p[i].second.second<<"\n";
            cout<<p[i+1].second.first<<" "<<p[i+1].second.second<<"\n";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}