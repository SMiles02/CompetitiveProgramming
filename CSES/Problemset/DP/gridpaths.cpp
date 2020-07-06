#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    ll a[n][n];
    string s[n];
    for (int i=0;i<n;++i)
    {
        cin>>s[i];
    }
    if (s[0][0]=='*')
    {
        cout<<0;
        return 0;
    }
    a[0][0]=1;
    for (int i=1;i<n;++i)
    {
        if (s[i][0]=='*')
        {
            a[i][0]=0;
        }
        else
        {
            a[i][0]=a[i-1][0];
        }
    }
    for (int i=1;i<n;++i)
    {
        if (s[0][i]=='*')
        {
            a[0][i]=0;
        }
        else
        {
            a[0][i]=a[0][i-1];
        }
    }
    for (int i=1;i<n;++i)
    {
        for (int j=1;j<n;++j)
        {
            if (s[i][j]=='*')
            {
                a[i][j]=0;
            }
            else
            {
                a[i][j]=(a[i-1][j]+a[i][j-1])%1000000007;
            }
        }
    }
    cout<<a[n-1][n-1];
    return 0;
}