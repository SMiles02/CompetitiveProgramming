#include <bits/stdc++.h>
using namespace std;
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,l,r,mid;
    cin>>n>>m;
    array<int,2> a[m];
    for (int i=0;i<m;++i)
    {
        cin>>a[i][0]>>a[i][1];
        a[i][1]*=-1;
    }
    sort(a,a+m);
    for (int i=0;i<m;++i)
        a[i][1]*=-1;
    vector<int> lis(n+3, n+1);
    lis[0]=0;
    for (int i=0;i<m;++i)
    {
        l=0;
        r=n;
        while (l<r)
        {
            mid=l+(r-l)/2+1;
            if (lis[mid]<a[i][1])
                l=mid;
            else
                r=mid-1;
        }
        lis[l+1]=min(lis[l+1],a[i][1]);
    }
    for (int i=n+2;i>=0;--i)
        if (lis[i]<=n)
        {
            cout<<i;
            return 0;
        }
    return 0;
}