#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll sum=0,ans;
    map<ll,int> m; //previous occurences
    int n,cur;
    cin>>n;
    int rightBound[n+2];
    m[0]=1;
    for (int i=2;i<=n+1;++i)
    {
        cin>>cur;
        sum+=cur;
        if (m[sum])
        {
            rightBound[m[sum]+1]=min(rightBound[m[sum]+1],i-m[sum]-1);
            rightBound[i]=n+2-i;
        }
        else
        {
            rightBound[i]=n+2-i;
        }
        if (cur==0)
        {
            rightBound[i]=0;
        }
        m[sum]=i;
    }
    ans=rightBound[n+1];
    for (int i=n;i>1;--i)
    {
        rightBound[i]=min(rightBound[i],rightBound[i+1]+1);
        ans+=rightBound[i];
    }
    cout<<ans;
    return 0;
}