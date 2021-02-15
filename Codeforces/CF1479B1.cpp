#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x=0,y=0,k,ans=0;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        if (k^x)
        {
            x=k;
            ++ans;
        }
        else if (k^y)
        {
            y=k;
            ++ans;
        }
    }
    cout<<ans;
    return 0;
}