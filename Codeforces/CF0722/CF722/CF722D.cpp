#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,a[50000],x;
set<int> s;

bool check(int k)
{
    s.clear();
    for (int i=0;i<n;++i)
    {
        x=a[i];
        while (x>k)
            x/=2;
        while (s.find(x)!=s.end())
            x/=2;
        if (x==0)
            return 0;
        s.insert(x);
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n,greater<int>());
    int l=1,r=1e9,m;
    while (l<r)
    {
        m=l+(r-l)/2;
        if (check(m))
            r=m;
        else
            l=m+1;
    }
    s.clear();
    for (int i=0;i<n;++i)
    {
        while (a[i]>l)
            a[i]/=2;
        while (s.find(a[i])!=s.end())
            a[i]/=2;
        cout<<a[i]<<" ";
        s.insert(a[i]);
    }
    return 0;
}