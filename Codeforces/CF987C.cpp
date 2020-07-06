#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,mini=1000000000,first,second,p1,p2;
    cin>>n;
    int s[n];
    int c[n];
    for (int i=0;i<n;++i)
    {
        cin>>s[i];
    }
    for (int i=0;i<n;++i)
    {
        cin>>c[i];
    }
    for (int i=1;i<n-1;++i)
    {
        p1=100000000;p2=100000000;first=0;second=0;
        for (int j=0;j<i;++j)
        {
            if (s[j]<s[i])
            {
                first=1;
                p1=min(p1,c[j]);
            }
        }
        for (int j=i+1;j<n;++j)
        {
            if (s[j]>s[i])
            {
                second=1;
                p2=min(p2,c[j]);
            }
        }
        if (first&&second)
        {
            mini=min(mini,p1+p2+c[i]);
        }
    }
    if (mini==1000000000)
    {
        mini=-1;
    }
    cout<<mini;
    return 0;
}