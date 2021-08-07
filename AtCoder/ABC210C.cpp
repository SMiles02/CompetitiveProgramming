#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,ans=0,cur=0;
    cin>>n>>k;
    int a[n];
    map<int,int> m;
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<k;++i)
        if (++m[a[i]]==1)
            ++cur;
    ans=cur;
    for (int i=k;i<n;++i)
    {
        if (--m[a[i-k]]==0)
            --cur;
        if (++m[a[i]]==1)
            ++cur;
        ans=max(ans,cur);
    }
    cout<<ans;
    return 0;
}