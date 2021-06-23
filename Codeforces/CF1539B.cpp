#include <bits/stdc++.h>
using namespace std;

int p[100005][26];
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,x,y,ans;
    cin>>n>>q;
    string s;
    cin>>s;
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<26;++j)
            p[i+1][j]=p[i][j];
        ++p[i+1][s[i]-'a'];
    }
    while (q--)
    {
        cin>>x>>y;
        ans=0;
        for (int i=0;i<26;++i)
            ans+=(p[y][i]-p[x-1][i])*(i+1);
        cout<<ans<<"\n";
    }
    return 0;
}