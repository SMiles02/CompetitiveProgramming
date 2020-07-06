#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int INF=1e9;
bool suitableEnd[1000000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a=INF,g=INF,c=INF,t=INF,ans=INF,cur,x;
    bool bb;
    string s;
    cin>>s;
    n=sz(s);
    int next[n][4];
    int dp[n];
    for (int i=n-1;i>=0;--i)
    {
        next[i][0]=a;
        next[i][1]=g;
        next[i][2]=c;
        next[i][3]=t;
        if (s[i]=='A') a=i;
        else if (s[i]=='G') g=i;
        else if (s[i]=='C') c=i;
        else t=i;
        for (int j=0;j<4;++j)
            if (next[i][j]==INF)
                suitableEnd[i]=1;
    }
    if (a==INF)
    {
        cout<<"A";
        return 0;
    }
    if (g==INF)
    {
        cout<<"G";
        return 0;
    }
    if (c==INF)
    {
        cout<<"C";
        return 0;
    }
    if (t==INF)
    {
        cout<<"T";
        return 0;
    }
    map<char,bool> m;
    for (int i=0;i<n;++i)
    {
        if (!m[s[i]])
        {
            m[s[i]]=1;
            dp[i]=1;
        }
        else
            dp[i]=INF;
    }
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<4;++j)
            if (next[i][j]<INF)
                dp[next[i][j]]=min(dp[next[i][j]],dp[i]+1);
        if (suitableEnd[i])
            ans=min(ans,dp[i]);
    }
    string ss="";
    for (int i=n-1;i>=0;--i)
        if (dp[i]==ans&&suitableEnd[i])
        {
            if (next[i][0]==INF) ss+='A';
            else if (next[i][1]==INF) ss+='G';
            else if (next[i][2]==INF) ss+='C';
            else ss+='T';
            ss+=s[i];
            cur=i;
            x=dp[cur];
            while (dp[cur]!=1)
            {
                bb=1;
                for (int j=cur-1;j>=0&&bb;--j)
                    for (int k=0;k<4;++k)
                        if (next[j][k]==cur&&dp[j]<x)
                        {
                            cur=j;
                            ss+=s[j];
                            bb=0;
                            --x;
                            break;
                        }
            }
            reverse(ss.begin(), ss.end());
            cout<<ss;
            return 0;
        }
    cout<<"huh\n";
    return 0;
}