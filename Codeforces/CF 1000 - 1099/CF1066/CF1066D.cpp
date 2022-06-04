#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,m,k;
int a[200000];

bool check(int x)
{
    int ans=1,cur=k;
    for (int i=x;i<n;++i)
    {
        if (cur-a[i]<0)
        {
            ++ans;
            cur=k-a[i];
        }
        else
            cur-=a[i];
    }
    if (ans>m)
        return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int l=0,r,mid;
    cin>>n>>m>>k;
    for (int i=0;i<n;++i)
        cin>>a[i];
    r=n-1;
    while (l<r)
    {
        mid=l+(r-l)/2;
        if (check(mid))
            r=mid;
        else
            l=mid+1;
    }
    cout<<n-l;
    return 0;
}