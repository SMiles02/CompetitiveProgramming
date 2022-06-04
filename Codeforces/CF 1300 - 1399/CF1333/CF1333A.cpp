#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t,n,m;
    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        cout<<"W";
        for (int i=1;i<m;++i)
        {
            cout<<"B";
        }
        cout<<"\n";
        for (int i=1;i<n;++i)
        {
            for (int j=0;j<m;++j)
            {
                cout<<"B";
            }
            cout<<"\n";
        }
    }
    return 0;
}