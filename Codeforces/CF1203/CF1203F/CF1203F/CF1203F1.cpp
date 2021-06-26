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

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first + a.second > b.first + b.second;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,r,a,b;
    cin>>n>>r;
    vector<pair<int,int>> increasing;
    vector<pair<int,int>> decreasing;
    while (n--)
    {
        cin>>a>>b;
        if (b>=0)
        {
            increasing.push_back({a,b});
        }
        else
        {
            a=max(a,-b);
            decreasing.push_back({a,b});
        }
    }
    sort(increasing.begin(), increasing.end());
    sort(decreasing.begin(), decreasing.end(),comp);
    n=sz(increasing);
    for (int i=0;i<n;++i)
    {
        //cout<<increasing[i].first<<" "<<increasing[i].second<<"\n";
        if (r<increasing[i].first)
        {
            //cout<<increasing[i].first<<" "<<increasing[i].second<<" "<<r<<"\n";
            cout<<"NO";return 0;
        }
        else
        {
            r+=increasing[i].second;
        }
        //cout<<"r="<<r<<"\n";
    }
    n=sz(decreasing);
    for (int i=0;i<n;++i)
    {
        //cout<<decreasing[i].first<<" "<<decreasing[i].second<<"\n";
        if (r<decreasing[i].first)
        {
            //cout<<decreasing[i].first<<" "<<decreasing[i].second<<" "<<r<<"\n";
            cout<<"NO";return 0;
        }
        else
        {
            r+=decreasing[i].second;
        }
        //cout<<"r="<<r<<"\n";
    }
    if (r<0)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
    return 0;
}