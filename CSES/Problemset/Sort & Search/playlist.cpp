#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,start=1,ans=0;
    cin>>n;
    int k[n+1];
    map<int,int> m;
    for (int i=1;i<=n;++i)
    {
        cin>>k[i];
        if (m[k[i]])
        {
            for (int j=start;j<m[k[i]];++j)
            {
                m[k[j]]=0;
            }
            start=m[k[i]]+1;
        }
        m[k[i]]=i;
        ans=max(ans,i-start+1);
    }
    cout<<ans;
    return 0;
}