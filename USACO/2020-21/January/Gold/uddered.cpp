#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int INF = 1e9, mn = 23;

int dp[(1<<mn)], occ[26][26], num[26];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin>>s;
    int c=0,n=sz(s),x;
    for (auto i : s)
        if (!num[i-'a'])
            num[i-'a']=++c;
    for (int i=0;i<26;++i)
        --num[i];
    for (int i=1;i<n;++i)
        ++occ[num[s[i-1]-'a']][num[s[i]-'a']];
    for (int i=1;i<(1<<c);++i)
    {
        dp[i]=INF;
        for (int j=0;j<c;++j)
            if (i&(1<<j))
            {
                x=0;
                for (int k=0;k<c;++k)
                    if (i&(1<<k))
                        x+=occ[j][k];
                dp[i]=min(dp[i],x+dp[i^(1<<j)]);
            }
    }
    cout<<dp[(1<<c)-1]+1;
    return 0;
}