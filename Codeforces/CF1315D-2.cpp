#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,b,maxi;
    ll ans=0;
    cin>>n;
    map<int,vector<int>> m;
    vector<int> v;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for (int i=0;i<n;++i)
    {
        cin>>b;
        if (!sz(m[a[i]]))
        {
            v.push_back(a[i]);
        }
        m[a[i]].push_back(b);
    }
    sort(v.begin(), v.end());
    //maybe comment this out??
    for (int i=0;i<sz(v);++i)
    {
        n=sz(m[v[i]]);
        //cout<<v[i]<<", size = "<<n<<"!\n";
        if (n>1)
        {
            maxi=m[v[i]][0];
            for (int j=1;j<n;++j)
            {
                ans+=min(m[v[i]][j],maxi);
                m[v[i]+1].push_back(min(m[v[i]][j],maxi));
                //cout<<"ans+="<<min(m[v[i]][j],maxi)<<"\n";
                maxi=max(m[v[i]][j],maxi);
            }
            v.push_back(v[i]+1);
            m[v[i]].clear();
            m[v[i]].push_back(maxi);
        }
    }
    cout<<ans<<"\n";
    return 0;
}