#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x;
    cin>>n>>x;
    int a[n];
    set<pair<int,pair<int,int>>> s;
    s.insert({2e9+1,{2000,2000}});
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        for (int j=0;j<i;++j)
            s.insert({a[i]+a[j],{i,j}});
    }
    for (int i=0;i<n;++i)
    {
        for (int j=i+1;j<n;++j)
            s.erase({a[i]+a[j],{j,i}});
        for (int j=0;j<i;++j)
            if (a[i]+a[j]<x)
                if ((*s.lower_bound({x-a[i]-a[j],{0,0}})).first==x-a[i]-a[j])
                {
                    cout<<i+1<<" "<<j+1<<" "<<(*s.lower_bound({x-a[i]-a[j],{0,0}})).second.first+1<<" "<<(*s.lower_bound({x-a[i]-a[j],{0,0}})).second.second+1;
                    return 0;
                }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}