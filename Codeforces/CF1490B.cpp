#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t,n,x,r[3],ans;
    cin>>t;
    while (t--)
    {
        ans=0;
        cin>>n;
        for (int i=0;i<3;++i)
            r[i]=0;
        for (int i=0;i<n;++i)
        {
            cin>>x;
            ++r[x%3];
        }
        for (int i=0;i<6;++i)
            while (r[i%3]>n/3)
            {
                ++ans;
                --r[i%3];
                ++r[(i+1)%3];
            }
        cout<<ans<<"\n";
    }
    return 0;
}