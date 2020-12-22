#include <bits/stdc++.h>
using namespace std;

bitset<10001> dp[100];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k,n;
    string s;
    char c;
    cin>>s;
    cin>>k;
    n=s.size();
    for (int i=0;i<n;++i)
        dp[i][0]=1;
    for (int j=1;j<=k;++j)
    {
        c='z';
        for (int i=0;i<n;++i)
            if ((i+1<n&&dp[i+1][j-1])||(0<=i-1&&dp[i-1][j-1]))
                if (s[i]<c)
                    c=s[i];
        cout<<c;
        for (int i=0;i<n;++i)
            if ((i+1<n&&dp[i+1][j-1])||(0<=i-1&&dp[i-1][j-1]))
                if (s[i]==c)
                    dp[i][j]=1;
    }
    return 0;
}