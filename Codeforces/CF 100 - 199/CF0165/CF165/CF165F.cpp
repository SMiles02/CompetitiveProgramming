#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    vector<int> ans(1<<22,-1);
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        ans[a[i]]=a[i];
    }
    for (int i=0;i<(1<<22);++i)
        if (ans[i]!=-1)
            for (int j=0;j<22;++j)
                if (((1<<j)&i)==0)
                    ans[i^(1<<j)]=ans[i];
    for (int i=0;i<n;++i)
        cout<<ans[((1<<22)-1)^a[i]]<<" ";
    return 0;
}