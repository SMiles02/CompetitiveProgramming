#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

bool check(int k, vector<ll> v)
{
    int cur=sz(v)-2;
    for (int i=k-1;i+1;--i)
    {
        if (v[i]*3>v[cur])
            return 0;
        cur-=2;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,l,r,m;
    cin>>n;
    vector<ll> v(n*3);
    for (int i=0;i<n*3;++i)
        cin>>v[i];
    sort(v.begin(), v.end());
    l=0;r=n;
    while (l<r)
    {
        m=l+(r-l)/2+1;
        if (check(m,v))
            l=m;
        else
            r=m-1;
    }
    cout<<l;
    return 0;
}