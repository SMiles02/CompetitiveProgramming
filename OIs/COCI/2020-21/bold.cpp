#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    string s[n];
    for (int i=0;i<n;++i)
        cin>>s[i];
    for (int i=n-1;i+1;--i)
        for (int j=m-1;j+1;--j)
            if (s[i][j]=='#')
                for (int k=i;k<i+2;++k)
                    for (int l=j;l<j+2;++l)
                        s[k][l]='#';
    for (int i=0;i<n;++i)
        cout<<s[i]<<"\n";
    return 0;
}