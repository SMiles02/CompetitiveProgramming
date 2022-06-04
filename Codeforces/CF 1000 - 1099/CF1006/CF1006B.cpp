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
    int n,k,x,ans=0;
    cin>>n>>k;
    vector<pair<int,int>> v;
    vector<int> b;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        v.push_back(make_pair(x,i));
    }
    sort(v.rbegin(), v.rend());
    for (int i=0;i<k;++i)
    {
        b.push_back(v[i].second);
        ans+=v[i].first;
    }
    b.push_back(-1);
    sort(b.begin(),b.end());
    cout<<ans<<"\n";
    for (int i=1;i<k;++i)
    {
        cout<<b[i]-b[i-1]<<" ";
    }
    cout<<n-1-b[k-1];
    return 0;
}