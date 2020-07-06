#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,ans=0,cur;
    map<pair<int,int>,int> d;
    cin>>n>>m;
    int a[n][m];
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<m;++j)
        {
            cin>>a[i][j];
            if ((a[i][j]-1)%m==(j)%m&&a[i][j]<=n*m)
            {
                if (a[i][j]>(i*m+j+1))
                {
                    ++d[{j,n-((a[i][j]-(i*m+j+1))/m)}];
                    //cout<<"++d["<<j<<","<<n-((a[i][j]-(i*m+j+1))/m)<<"]!\n";
                }
                else
                {
                    ++d[{j,((i*m+j+1)-a[i][j])/m}];
                    //cout<<"++d["<<j<<","<<((i*m+j+1)-a[i][j])/m<<"]?\n";
                }
            }
        }
    }
    for (int j=0;j<m;++j)
    {
        cur=n;
        //cout<<"j="<<j<<"\n";
        for (int i=0;i<n;++i)
        {
            //cout<<"cur could be "<<n-d[{j,i}]+i<<"\n";
            cur=min(cur,n-d[{j,i}]+i);
        }
        ans+=cur;
    }
    cout<<ans;
    return 0;
}