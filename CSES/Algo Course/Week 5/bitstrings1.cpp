#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    ll ans=0;
    cin>>n>>k;
    ll white[n][k];
    ll black[n][k];
    for (int i=1;i<k;++i)
    {
        white[0][i]=0;
        black[0][i]=0;
    }
    white[0][0]=1;
    black[0][0]=1;
    for (int i=1;i<n;++i)
    {
        white[i][0]=black[i-1][k-1];
        black[i][0]=white[i-1][k-1];
        for (int j=1;j<k;++j)
        {
            white[i][j]=white[i-1][j-1];
            black[i][j]=black[i-1][j-1];
            white[i][0]+=black[i-1][j-1];
            black[i][0]+=white[i-1][j-1];
        }
        white[i][0]%=1000000007;
        black[i][0]%=1000000007;
        /**for (int j=0;j<k;++j)
        {
            cout<<"white["<<i<<"]["<<j<<"] = "<<white[i][j]<<"\n";
            cout<<"black["<<i<<"]["<<j<<"] = "<<black[i][j]<<"\n";
        }**/
    }
    for (int i=0;i<k;++i)
    {
        ans+=white[n-1][i];
        ans+=black[n-1][i];
    }
    cout<<ans%1000000007;
    return 0;
}