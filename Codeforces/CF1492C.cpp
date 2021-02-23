#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x;
    cin>>n>>m;
    string s,t;
    cin>>s;
    cin>>t;
    int a[m],b[m];
    x=0;
    for (int i=0;i<n&&x<m;++i)
        if (s[i]==t[x])
            a[x++]=i;
    x=m-1;
    for (int i=n-1;i>=0&&x>=0;--i)
        if (s[i]==t[x])
            b[x--]=i;
    x=0;
    for (int i=0;i+1<m;++i)
        x=max(x,b[i+1]-a[i]);
    cout<<x;
    return 0;
}