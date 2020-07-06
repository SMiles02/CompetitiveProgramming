#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,xInd,yInd,c,diag1=0,diag2=0,ans;
    cin>>n;
    ll a[n][n];
    ll row[n];
    if (n==1)
    {
        cout<<5;
        return 0;
    }
    for (int i=0;i<n;++i)
    {
        c=0;
        for (int j=0;j<n;++j)
        {
            cin>>a[i][j];
            if (a[i][j]==0)
            {
                xInd=i;
                yInd=j;
            }
            c+=a[i][j];
        }
        row[i]=c;
    }
    if (xInd==0)
    {
        ans=row[1]-row[xInd];
    }
    else
    {
        ans=row[0]-row[xInd];
    }
    if (ans<=0)
    {
        cout<<-1;
        return 0;
    }
    a[xInd][yInd]=ans;
    row[xInd]+=ans;
    for (int i=1;i<n;++i)
    {
        if (row[0]!=row[i])
        {
            cout<<-1;
            return 0;
        }
    }
    for (int j=0;j<n;++j)
    {
        c=0;
        for (int i=0;i<n;++i)
        {
            c+=a[i][j];
        }
        if (c!=row[0])
        {
            cout<<-1;
            return 0;
        }
    }
    for (int i=0;i<n;++i)
    {
        diag1+=a[i][i];
        diag2+=a[n-i-1][i];
    }
    if (diag1!=row[0])
    {
        cout<<-1;
        return 0;
    }
    if (diag2!=row[0])
    {
        cout<<-1;
        return 0;
    }
    cout<<ans;
    return 0;
}