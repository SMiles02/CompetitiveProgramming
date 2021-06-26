#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ans=0;
    cin>>n;
    string s;
    cin>>s;
    int pre[n+2],suf[n+2];
    pre[0]=suf[n+1]=0;
    for (int i=1;i<=n;++i)
    {
        if (pre[i-1]==INF)
        {
            pre[i]=INF;
            continue;
        }
        pre[i]=pre[i-1];
        if (s[i-1]=='(')
            ++pre[i];
        else
            --pre[i];
        if (pre[i]<0)
            pre[i]=INF;
    }
    for (int i=n;i;--i)
    {
        if (suf[i+1]==INF)
        {
            suf[i]=INF;
            continue;
        }
        suf[i]=suf[i+1];
        if (s[i-1]=='(')
            ++suf[i];
        else
            --suf[i];
        if (suf[i]>0)
            suf[i]=INF;
    }
    for (int i=0;i<n;++i)
    {
        if (s[i]=='('&&pre[i]^INF&&suf[i+2]^INF&&pre[i]+suf[i+2]-1==0)
            ++ans;
        if (s[i]==')'&&pre[i]^INF&&suf[i+2]^INF&&pre[i]+suf[i+2]+1==0)
            ++ans;
    }
    cout<<ans;
    return 0;
}