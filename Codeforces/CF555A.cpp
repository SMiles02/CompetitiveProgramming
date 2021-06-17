#include <bits/stdc++.h>
using namespace std;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x,y,ans;
    cin>>n>>k;
    ans=n-1;
    while (k--)
    {
        cin>>x;
        vector<int> v(x);
        for (auto& i : v)
            cin>>i;
        if (v[0]==1)
        {
            y=1;
            for (int i=1;i<x;++i)
            {
                if (v[i]==v[i-1]+1)
                    ++y;
                else
                    break;
            }
            ans+=x-y*2+1;
        }
        else
            ans+=x-1;
    }
    cout<<ans;
    return 0;
}