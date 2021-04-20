#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,m;
string s[500];

void solve()
{
    cin>>n>>m;
    for (int i=0;i<n;++i)
        cin>>s[i];
    if (n%3)
    {
        for (int i=0;i<n;i+=3)
            for (int j=0;j<m;++j)
                s[i][j]='X';
        for (int i=2;i<n;i+=3)
        {
            bool d = 0;
            for (int j=0;j<m&&!d;++j)
                if (s[i][j]=='X'||s[i-1][j]=='X')
                {
                    d=1;
                    s[i][j]='X';
                    s[i-1][j]='X';
                }
            if (!d)
            {
                s[i][0]='X';
                s[i-1][0]='X';
            }
        }
    }
    else
    {
        for (int i=1;i<n;i+=3)
            for (int j=0;j<m;++j)
                s[i][j]='X';
        for (int i=3;i<n;i+=3)
        {
            bool d = 0;
            for (int j=0;j<m&&!d;++j)
                if (s[i][j]=='X'||s[i-1][j]=='X')
                {
                    d=1;
                    s[i][j]='X';
                    s[i-1][j]='X';
                }
            if (!d)
            {
                s[i][0]='X';
                s[i-1][0]='X';
            }
        }
    }
    for (int i=0;i<n;++i)
        cout<<s[i]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}