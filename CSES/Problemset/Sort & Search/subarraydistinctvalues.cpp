#include <bits/stdc++.h>
using namespace std;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x=0,ct=1;
    long long ans=0;
    cin>>n>>k;
    int a[n];
    map<int,int> m;
    for (int i=0;i<n;++i)
        cin>>a[i];
    ++m[a[0]];
    while (x+1<n)
    {
        if (m[a[x+1]]==0)
        {
            if (ct==k)
                break;
            ++ct;
        }
        ++m[a[++x]];
    }
    ans+=x+1;
    for (int i=1;i<n;++i)
    {
        if (--m[a[i-1]]==0)
            --ct;
        while (x+1<n)
        {
            if (m[a[x+1]]==0)
            {
                if (ct==k)
                    break;
                ++ct;
            }
            ++m[a[++x]];
        }
        ans+=x-i+1;
    }
    cout<<ans;
    return 0;
}