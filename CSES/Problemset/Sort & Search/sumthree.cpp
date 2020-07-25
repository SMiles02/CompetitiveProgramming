#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x;
    cin>>n>>x;
    multiset<int> s;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        s.insert(a[i]);
    }
    for (int i=0;i+1<n;++i)
    {
        s.erase(s.lower_bound(a[i]));
        for (int j=0;j<i;++j)
            if (a[i]+a[j]<x)
                if (s.find(x-a[i]-a[j])!=s.end())
                    for (int k=i+1;k<n;++k)
                        if (a[k]==x-a[i]-a[j])
                        {
                            cout<<j+1<<" "<<i+1<<" "<<k+1<<"\n";
                            return 0;
                        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}