#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
 
const int maxn = 3e5+7;
int n,a[maxn],b[maxn],c[maxn];
 
ll find_inversions(int l, int r)
{
    if (l==r)
        return 0;
    int m=l+((r-l)>>1),x=l,y=m+1;
    ll ans=find_inversions(l,m)+find_inversions(m+1,r);
    for (int i=l;i<=r;++i)
    {
        if (x>m)
            c[i]=b[y++];
        else if (y>r)
            c[i]=b[x++];
        else if (b[x]>b[y])
        {
            c[i]=b[y++];
            ans+=m-x+1;
        }
        else
            c[i]=b[x++];
    }
    for (int i=l;i<=r;++i)
        b[i]=c[i];
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    //find_inversions(0,n-1);
    return 0;
}