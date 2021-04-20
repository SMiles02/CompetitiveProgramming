#include <bits/stdc++.h>
using namespace std;

bitset<5001> dp[5001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ans=1,l,y;
    cin>>n;
    int a[n+1],x[n+1];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
        cin>>x[i];
    for (int i=1;i<=n;++i)
    {
        dp[i][1]=1;
        for (int j=2;j<=i;++j)
            for (int k=j-1;k<i;++k)
                if (dp[k][j-1]&&__builtin_popcount(a[i]&a[k])==x[j])
                {
                    dp[i][j]=1;
                    ans=max(ans,j);
                    break;
                }
    }
    cout<<ans<<"\n";
    for (int i=1;i<=n;++i)
        if (dp[i][ans])
        {
            stack<int> s;
            s.push(i);
            l=i;y=ans-1;
            for (int j=i-1;j;--j)
                if (dp[j][y]&&__builtin_popcount(a[j]&a[l])==x[y+1])
                {
                    s.push(j);
                    l=j;
                    --y;
                }
            while (!s.empty())
            {
                cout<<s.top()<<" ";
                s.pop();
            }
            return 0;
        }
    return 0;
}