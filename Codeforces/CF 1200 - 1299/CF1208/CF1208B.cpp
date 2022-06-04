#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ans,t,k;
    map<int,int> m;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    ans=n-1;
    for (int i=0;i<=n;++i)
    {
        t=1;
        for (int j=0;j<i;++j)
        {
            if (m[a[j]])
            {
                t=0;
                break;
            }
            ++m[a[j]];
        }
        //cout<<"!! "<<i<<" "<<t<<"\n";
        if (t)
        {
            ans=min(ans,n-i);
            for (k=1;n-k>=i;++k)
            {
                if (m[a[n-k]])
                {
                    break;
                }
                ++m[a[n-k]];
                //cout<<i<<" "<<k<<"\n";
                ans=min(ans,n-i-k);
            }
        }
        m.clear();
    }
    cout<<ans;
    return 0;
}