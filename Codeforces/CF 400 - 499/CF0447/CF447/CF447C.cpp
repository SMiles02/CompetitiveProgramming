#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ans=1;
    cin>>n;
    int a[n];
    int pref[n];
    int suf[n];
    cin>>a[0];
    pref[0]=1;
    for (int i=1;i<n;++i)
    {
        cin>>a[i];
        if (a[i]>a[i-1])
        {
            pref[i]=pref[i-1]+1;
        }
        else
        {
            pref[i]=1;
        }
        ans=max(ans,pref[i]+1);
    }
    suf[n-1]=1;
    for (int i=n-2;i+1;--i)
    {
        if (a[i]<a[i+1])
        {
            suf[i]=suf[i+1]+1;
        }
        else
        {
            suf[i]=1;
        }
    }
    for (int i=0;i<n-2;++i)
    {
        if (a[i]+1<a[i+2])
        {
            ans=max(ans,pref[i]+suf[i+2]+1);
        }
    }
    cout<<min(ans,n);
    return 0;
}