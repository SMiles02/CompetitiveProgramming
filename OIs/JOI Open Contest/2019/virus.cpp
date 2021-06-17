#include <bits/stdc++.h>
using namespace std;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k,n,m,e=0,w=0,a1,a2=0,l,r;
    cin>>k>>n>>m;
    string s;
    cin>>s;
    int a[n][m];
    a1=n*m;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            cin>>a[i][j];
    vector<int> v={1};
    if (s[0]=='E')
        e=1;
    else
        w=1;
    for (int i=1;i<k;++i)
    {
        if (s[i]==s[i-1])
            ++v.back();
        else
            v.push_back(1);
        if (s[i]=='E')
            e=max(e,v.back());
        else
            w=max(w,v.back());
    }
    if (e==0)
        w=1000000;
    else if (w==0)
        e=1000000;
    if (s[0]==s[k-1])
    {
        if (s[0]=='E')
            e=max(e,v[0]+v.back());
        else
            w=max(w,v[0]+v.back());
    }
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            if (a[i][j]!=0)
            {
                l=j;r=j;
                while (0<l&&a[i][l-1]<=e&&a[i][l-1]!=0)
                    --l;
                while (r+1<n&&a[i][r+1]<=w&&a[i][r+1]!=0)
                    ++r;
                if (r-l+1<a1)
                {
                    a1=r-l+1;
                    a2=0;
                }
                if (r-l+1==a1)
                    ++a2;
            }
    cout<<a1<<"\n"<<a2;
    return 0;
}