#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

bool ans[50][50];

void solve()
{
    int n,m,a,b,cur=0;
    cin>>n>>m>>a>>b;
    if (n*a==m*b)
    {
        cout<<"YES\n";
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                ans[i][j]=0;
        for (int i=0;i<m;++i)
        {
            for (int j=cur;j<cur+b;++j)
                ans[j%n][i]=1;
            cur+=b;
        }
        for (int i=0;i<n;++i)
        {
            for (int j=0;j<m;++j)
                cout<<ans[i][j];
            cout<<"\n";
        }
        return;
    }
    else
    {
        cout<<"NO\n";
        return;
    }
    
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