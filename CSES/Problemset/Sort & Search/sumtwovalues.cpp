#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,k;
    cin>>n>>x;
    map<int,int> m;
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        if (m[x-k])
        {
            cout<<m[x-k]<<" "<<i;
            return 0;
        }
        m[k]=i;
    }
    cout<<"IMPOSSIBLE";
    return 0;
}