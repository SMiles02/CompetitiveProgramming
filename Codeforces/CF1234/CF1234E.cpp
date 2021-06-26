#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[200001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y;
    cin>>n>>m;
    cin>>x;
    for (int i=1;i<m;++i)
    {
        cin>>y;
        if (x==y)
            continue;
        a[0]+=abs(x-y);
        a[min(x,y)]+=max(x,y)-1-abs(x-y);
        if (min(x,y)+1==max(x,y))
            a[max(x,y)]+=min(x,y)+1-max(x,y);
        else
        {
            a[min(x,y)+1]+=abs(x-y)-max(x,y);
            a[max(x,y)]+=min(x,y)+1-abs(x-y);
        }
        a[max(x,y)+1]+=abs(x-y)-min(x,y);
        x=y;
    }
    for (int i=1;i<=n;++i)
    {
        a[i]+=a[i-1];
        cout<<a[i]<<" ";
    }
    return 0;
}