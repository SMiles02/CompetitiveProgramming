#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

int amounts[16][26],lengths[16],dp[1<<16],cur[26];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,p,x;
    cin>>n;
    string s;
    for (int i=0;i<n;++i)
    {
        cin>>s;
        for (auto c : s)
            ++amounts[i][c-'a'];
        lengths[i]=sz(s);
    }
    p=(1<<(n));
    for (int i=1;i<p;++i)
    {
        if (__builtin_popcount(i)==1)
        {
            for (int j=0;j<n;++j)
                if ((1<<j)==i)
                    dp[i]=lengths[j];
            continue;
        }
        dp[i]=1000000;
        for (int j=0;j<26;++j)
            cur[j]=1000000;
        for (int j=0;j<n;++j)
            if ((1<<j)&i)
                for (int k=0;k<26;++k)
                    cur[k]=min(cur[k],amounts[j][k]);
        x=0;
        for (int j=0;j<26;++j)
            x+=cur[j];
        for (int j=(i-1)&i;j;j=(j-1)&i)
            dp[i]=min(dp[i],dp[j]+dp[i-j]-x);
    }
    cout<<dp[p-1]+1;
    return 0;
}