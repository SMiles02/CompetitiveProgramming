#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,l,r,minDist=1000000,curX=0,curY=0;
    string s;
    cin>>n;
    cin>>s;
    map<pair<int,int>,int> m;
    for (int i=0;i<n;++i)
    {
        if (m[{curX,curY}])
        {
            if (i-m[{curX,curY}]<minDist)
            {
                minDist=i-m[{curX,curY}];
                l=m[{curX,curY}];
                r=i;
            }
        }
        m[{curX,curY}]=i+1;
        if (s[i]=='L')
        {
            --curX;
        }
        else if (s[i]=='R')
        {
            ++curX;
        }
        else if (s[i]=='U')
        {
            ++curY;
        }
        else
        {
            --curY;
        }
    }
    if (m[{curX,curY}])
    {
        if (n-m[{curX,curY}]<minDist)
        {
            minDist=n-m[{curX,curY}];
            l=m[{curX,curY}];
            r=n;
        }
    }
    if (minDist==1000000)
    {
        cout<<"-1\n";
    }
    else
    {
        cout<<l<<" "<<r<<"\n";
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}