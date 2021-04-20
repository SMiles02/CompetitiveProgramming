#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int m[200001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,o;
    ll ans=0;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        for (int j=1;j<=n;++j)
            m[j]=0;
        o=0;
        for (int j=i-1;j>=0;--j)
        {
            if (a[j]==a[i])
                break;
            if (m[a[j]]>0)
            {
                if (++m[a[j]]==2)
                    --o;
                continue;
            }
            ans+=o;
            m[a[j]]=1;
            ++o;
        }
    }
    cout<<ans;
    return 0;
}