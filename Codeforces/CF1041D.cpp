#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,h,left,right,mid,ans=0,k;
    cin>>n>>h;
    int points[n+1][2];
    int goodArea[n+1];
    goodArea[0]=0;
    for (int i=1;i<=n;++i)
    {
        cin>>points[i][0]>>points[i][1];
        goodArea[i]=goodArea[i-1]+points[i][1]-points[i][0];
    }
    for (int i=1;i<=n;++i)
    {
        left=i;right=n;
        mid=right-(right-left)/2;
        while (left!=right)
        {
            mid=right-(right-left)/2;
            if (points[mid][0]-points[i][1]-goodArea[mid-1]+goodArea[i]<h)
            {
                left=mid;
            }
            else
            {
                right=mid-1;
            }
        }
        k=h-points[right][0]+points[i][1]+goodArea[right-1]-goodArea[i];
        k+=points[right][1]-points[i][0];
        //cout<<i<<" "<<right<<" "<<k<<"\n";
        //cout<<goodArea[right]<<" "<<goodArea[i-1]<<"\n";
        ans=max(ans,k);
    }
    cout<<ans;
    return 0;
}