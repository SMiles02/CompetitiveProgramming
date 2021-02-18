#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,l,r,m;
    cin>>n;
    int ans[n];
    array<int,3> a[n];
    array<int,2> w[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i][0]>>a[i][1];
        a[i][2]=i;
        ans[i]=-2;
    }
    sort(a,a+n);
    w[0][0]=a[0][1];
    w[0][1]=a[0][2];
    for (int i=1;i<n;++i)
    {
        if (a[i][1]<w[i-1][0])
        {
            w[i][0]=a[i][1];
            w[i][1]=a[i][2];
        }
        else
            w[i]=w[i-1];
    }
    for (int i=0;i<n;++i)
    {
        if (a[0][0]<a[i][0])
        {
            l=0;r=i-1;
            while (l!=r)
            {
                m=l+(r-l)/2+1;
                if (a[m][0]<a[i][0])
                    l=m;
                else
                    r=m-1;
            }
            if (w[l][0]<a[i][1])
            {
                ans[a[i][2]]=w[l][1];
                continue;
            }
        }
        if (a[0][0]<a[i][1])
        {
            l=0;r=n-1;
            while (l!=r)
            {
                m=l+(r-l)/2+1;
                if (a[m][0]<a[i][1])
                    l=m;
                else
                    r=m-1;
            }
            if (w[l][0]<a[i][0])
                ans[a[i][2]]=w[l][1];
        }
    }
    for (int i=0;i<n;++i)
        cout<<++ans[i]<<" ";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}