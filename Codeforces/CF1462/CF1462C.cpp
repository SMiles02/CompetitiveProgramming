#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t,n,m;
    cin>>t;
    while (t--)
    {
        cin>>n;
        m=n;
        if (n>45)
        {
            cout<<"-1\n";
            continue;
        }
        string ans="";
        for (int i=9;i;--i)
            if (i<=m)
            {
                m-=i;
                ans+=(i+'0');
            }
        sort(ans.begin(), ans.end());
        cout<<ans<<"\n";
    }
    return 0;
}