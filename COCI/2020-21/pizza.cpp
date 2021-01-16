#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int f[101];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,ans=0,cur;
    cin>>n;
    while (n--)
    {
        cin>>k;
        f[k]=1;
    }
    cin>>n;
    ans+=n;
    while (n--)
    {
        cin>>m;
        cur=0;
        while (m--)
        {
            cin>>k;
            cur=max(cur,f[k]);
        }
        ans-=cur;
    }
    cout<<ans;
    return 0;
}