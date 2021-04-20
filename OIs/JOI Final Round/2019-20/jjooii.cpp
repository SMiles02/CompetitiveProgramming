#include <bits/stdc++.h>
using namespace std;

int p[200001][3];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,ans,l,r,m,x;
    cin>>n>>k;
    ans=n;
    string s;
    cin>>s;
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<3;++j)
            p[i+1][j]=p[i][j];
        if (s[i]=='J')
            ++p[i+1][0];
        if (s[i]=='O')
            ++p[i+1][1];
        if (s[i]=='I')
            ++p[i+1][2];
    }
    for (int i=1;i<=n;++i)
    {
        if (p[n][0]-p[i-1][0]<k)
            break;
        x=i-1;l=x+1;r=n;
        while (l<r)
        {
            m=l+(r-l)/2;
            if (p[m][0]-p[x][0]<k)
                l=m+1;
            else
                r=m;
        }
        if (p[n][1]-p[l][1]<k)
            break;
        x=l;l=x+1;r=n;
        while (l<r)
        {
            m=l+(r-l)/2;
            if (p[m][1]-p[x][1]<k)
                l=m+1;
            else
                r=m;
        }
        if (p[n][2]-p[l][2]<k)
            break;
        x=l;l=x+1;r=n;
        while (l<r)
        {
            m=l+(r-l)/2;
            if (p[m][2]-p[x][2]<k)
                l=m+1;
            else
                r=m;
        }
        ans=min(ans,l-i+1-k*3);
    }
    if (ans==n)
        ans=-1;
    cout<<ans;
    return 0;
}