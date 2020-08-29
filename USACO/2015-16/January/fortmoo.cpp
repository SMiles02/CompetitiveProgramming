#include <bits/stdc++.h>
#define ll long long
using namespace std;

int dp1[201][201];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("fortmoo.in", "r", stdin);
    freopen("fortmoo.out", "w", stdout);
    int n,m,ans=0;
    cin>>n>>m;
    string s[n];
    for (int i=0;i<n;++i)
        cin>>s[i];
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
        {
            if (s[i][j]=='X')
                dp1[i+1][j+1]=dp1[i+1][j]+1;
            else
                dp1[i+1][j+1]=dp1[i+1][j];
        }
    for (int j=0;j<m;++j)
        for (int i=0;i<n;++i)
        {
            if (s[i][j]=='X')
                dp2[i+1][j+1]=dp2[i][j+1]+1;
            else
                dp2[i+1][j+1]=dp2[i][j+1];
        }
    for (int i=0;i<n;++i)
        
	return 0;
}