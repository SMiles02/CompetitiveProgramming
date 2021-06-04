#include <bits/stdc++.h>
using namespace std;

bitset<200001> dp;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,s=0,o=0;
    cin>>n;
    int a[n];
    dp[0]=1;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        s+=a[i];
        if (a[i]&1)
            o=i+1;
        dp|=dp<<a[i];
    }
    if (s&1||dp[s/2]==0)
    {
        cout<<0;
        return 0;
    }
    while (o==0)
    {
        for (int i=0;i<n;++i)
        {
            a[i]/=2;
            if (a[i]&1)
                o=i+1;
        }
    }
    cout<<"1\n"<<o;
    return 0;
}