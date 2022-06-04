#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

string s[50];
int r[50];
int c[50];

void solve()
{
    int n;
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>s[i];
    for (int i=0;i<n;++i)
    {
        r[i]=n;
        c[i]=n;
    }
    for (int i=n-1;i>=0;--i)
        for (int j=i;j>=0;--j)
        {
            if (s[i][j]=='1')
            {
                if (r[i]==j+1||c[j]==i+1)
                {
                    r[i]=j;
                    c[j]=i;
                }
                else
                {
                    cout<<"NO\n";
                    return;
                }
            }
            if (s[j][i]=='1'&&i!=j)
            {
                if (r[j]==i+1||c[i]==j+1)
                {
                    r[j]=i;
                    c[i]=j;
                }
                else
                {
                    cout<<"NO\n";
                    return;
                }
            }

        }
    cout<<"YES\n";
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