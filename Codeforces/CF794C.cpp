#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,b,w,x,y,z;
    string s,t,ans;
    cin>>s;
    cin>>t;
    n=sz(s);
    w=0;y=0;
    if (n%2)
    {
        x=n/2;
        z=n/2-1;
    }
    else
    {
        x=n/2-1;
        z=n/2-1;
    }
    a=0;b=n-1;
    for (int i=0;i<n;++i)
        ans+=".";
    sort(s.begin(), s.end());
    sort(t.rbegin(), t.rend());
    for (int i=0;i<n;++i)
    {
        if (i%2)
        {
            if (s[w]>=t[y])
            {
                ans[b]=t[z];
                --z;
                --b;
            }
            else
            {
                ans[a]=t[y];
                ++y;
                ++a;
            }
        }
        else
        {
            if (s[w]>=t[y])
            {
                ans[b]=s[x];
                --x;
                --b;
            }
            else
            {
                ans[a]=s[w];
                ++w;
                ++a;
            }
        }
    }
    cout<<ans;
}