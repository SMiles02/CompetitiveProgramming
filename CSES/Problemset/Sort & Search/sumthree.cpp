#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x;
    cin>>n>>x;
    map<int,int> m;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        ++m[a[i]];
    }
    for (int i=0;i<n;++i)
        for (int j=i+1;j<n;++j)
            if (a[i]+a[j]<x)
            {
                if (a[i]==x-a[i]-a[j]&&a[i]==a[j])
                {
                    if (m[a[i]]>2)
                    {
                        cout<<a[i]<<" "<<a[i]<<" "<<a[i]<<"\n";
                        return 0;
                    }
                }
                else if (a[i]==x-a[i]-a[j])
                {
                    if (m[a[i]]>1)
                    {
                        cout<<a[i]<<" "<<a[i]<<" "<<a[j]<<"\n";
                        return 0;
                    }
                }
                else if (a[j]==x-a[i]-a[j])
                {
                    if (m[a[j]]>1)
                    {
                        cout<<a[i]<<" "<<a[j]<<" "<<a[j]<<"\n";
                        return 0;
                    }
                }
                else
                {
                    if (m[x-a[i]-a[j]])
                    {
                        cout<<a[i]<<" "<<a[j]<<" "<<x-a[i]-a[j]<<"\n";
                        return 0;
                    }
                }
            }
    cout<<"IMPOSSIBLE";
    return 0;
}