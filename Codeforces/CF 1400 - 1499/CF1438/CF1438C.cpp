#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t,n,m,x;
    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        while (n--)
        {
            for (int j=0;j<m;++j)
            {
                cin>>x;
                if ((x&1)!=((n+j)&1))
                    ++x;
                cout<<x<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}