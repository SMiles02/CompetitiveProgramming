#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ans=0;
    cin>>n;
    int a[n][2];
    for (int i=0;i<n;++i)
    {
        cin>>a[i][0]>>a[i][1];
        for (int j=0;j<i;++j)
            if (-1<=(double)(a[i][1]-a[j][1])/(a[i][0]-a[j][0])&&(double)(a[i][1]-a[j][1])/(a[i][0]-a[j][0])<=1)
                ++ans;
    }
    cout<<ans;
    return 0;
}