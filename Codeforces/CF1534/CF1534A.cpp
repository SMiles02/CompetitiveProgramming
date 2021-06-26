#include <bits/stdc++.h>
using namespace std;

int a[2];
string ans[2];

void solve()
{
    int n,m,x=0,y=0;
    bool ok=1;
    cin>>n>>m;
    string s[n];
    for (int i=0;i<n;++i)
    {
        cin>>s[i];
        for (int j=0;j<m;++j)
        {
            if (s[i][j]=='R')
            {
                if (x==(a[(i+j)&1]^3))
                    ok=0;
                x=a[(i+j)&1];
            }
            else if (s[i][j]=='W')
            {
                if (y==(a[(i+j)&1]^3))
                    ok=0;
                y=a[(i+j)&1];
            }
        }
    }
    if (ok==0||(x!=0&&x==y))
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    if (x==0&&y==0)
        x=1,y=2;
    else if (x==0)
        x=y^3;
    else if (y==0)
        y=x^3;
    ans[x&1]='R';
    ans[y&1]='W';
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<m;++j)
            cout<<ans[(i+j)&1];
        cout<<"\n";
    }
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    a[0]=2;a[1]=1;
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}