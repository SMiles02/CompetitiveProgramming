#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int m,n,k,t;

int a[200000];
int loc[200000][3];

int check(int s)
{
    int fir=n,sec=1;
    for (int i=0;i<k;++i)
    {
        if (loc[i][2]>s)
        {
            fir=min(fir,loc[i][0]-1);
            sec=max(sec,loc[i][1]);
        }
    }
    return n+1+max(0,sec-fir)*2;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int l,r,mid;
    cin>>m>>n>>k>>t;
    for (int i=0;i<m;++i)
        cin>>a[i];
    sort(a,a+m);
    for (int i=0;i<k;++i)
        cin>>loc[i][0]>>loc[i][1]>>loc[i][2];
    if (check(a[m-1])>t)
    {
        cout<<0;
        return 0;
    }
    l=0;r=m-1;
    while (l<r)
    {
        mid=l+(r-l)/2;
        if (check(a[mid])>t)
            l=mid+1;
        else
            r=mid;
    }
    cout<<m-l;
    return 0;
}