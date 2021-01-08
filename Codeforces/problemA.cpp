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


int solve(vector<int>& v, int k) {
    int n=sz(v);
    int minPre[n],maxPre[n],minSuf[n],maxSuf[n];
    minPre[0]=maxPre[0]=v[0];
    for (int i=1;i<n;++i)
    {
        minPre[i]=min(minPre[i-1],v[i]);
        maxPre[i]=max(maxPre[i-1],v[i]);
    }
    minSuf[n-1]=maxSuf[n-1]=v[n-1];
    for (int i=n-2;i>=0;--i)
    {
        minSuf[i]=min(minSuf[i+1],v[i]);
        maxSuf[i]=max(maxSuf[i+1],v[i]);
    }
    int ans=min(maxSuf[k]-minSuf[k],maxPre[n-k-1]-minPre[n-k-1]);
    for (int i=1;i+k<n;++i)
    {
        ans=min(ans,max(maxPre[i-1],maxSuf[i+k])-min(minPre[i-1],minSuf[i+k]));
    }
    return ans;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for (int i=0;i<n;++i)
        cin>>v[i];
    cout<<solve(v,k);
}