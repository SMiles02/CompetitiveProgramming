#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,k;
int a[200000];

bool check(int x)
{
    vector<int> v;
    for (int i=0;i<n;++i)
    {
        if (sz(v)&1)
        {
            if (a[i]<=x)
                v.push_back(a[i]);
        }
        else
            v.push_back(a[i]);
    }
    if (sz(v)>=k)
        return 1;
    v.clear();
    for (int i=0;i<n;++i)
    {
        if (!(sz(v)&1))
        {
            if (a[i]<=x)
                v.push_back(a[i]);
        }
        else
            v.push_back(a[i]);
    }
    if (sz(v)>=k)
        return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    for (int i=0;i<n;++i)
        cin>>a[i];
    int l=1,r=1e9,m;
    while (l<r)
    {
        m=l+(r-l)/2;
        if (check(m))
            r=m;
        else
            l=m+1;
    }
    cout<<l;
    return 0;
}