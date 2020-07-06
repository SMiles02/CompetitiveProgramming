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
    int n,k,l,r,m,zeroCount=0,x;
    ll ans=0,cur;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    vector<int> positive;
    vector<int> other={0};
    for (int i=0;i<n;++i)
    {
        cin>>k;
        k=a[i]-k;
        if (k>0)
        {
            positive.push_back(k);
        }
        else if (k==0)
        {
            ++zeroCount;
        }
        else
        {
            other.push_back(k);
        }
    }
    k=sz(other);
    x=sz(positive);
    sort(other.rbegin(), other.rend());
    for (int i=0;i<x;++i)
    {
        l=0;r=k-1;
        while (l<r)
        {
            m=l+(r-l)/2;
            if (positive[i]+other[m]>0)
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        if (positive[i]+other[l]>0)
        {
            ++ans;
        }
        ans+=l-1;
    }
    cur=x;
    cur*=(x-1);
    ans+=cur/2;
    cur=x*zeroCount;
    ans+=cur;
    cout<<ans;
    return 0;
}