#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    string s;
    cin>>s;
    int n=sz(s),x=-1,y=-1,z=-1;
    int suff[n+1];
    bool rem[n+1];
    suff[n]=0;
    for (int i=n-1;i>=0;--i)
    {
        suff[i]=suff[i+1];
        if (s[i]=='b')
            ++suff[i];
    }
    for (int i=0;i<=n;++i)
        rem[0]=0;
    for (int i=0;i<n;++i)
        if (s[i]=='a')
        {
            if (x==-1)
            {
                if (suff[i])
                    x=i;
            }
            else
            {
                rem[x]=1;
                rem[i]=1;
                y=x;z=i;
                //cout<<x<<" "<<i<<"\n";
                x=-1;
            }
        }
    for (int i=0;i<n;++i)
        if (!rem[i])
            cout<<s[i];
    cout<<"\n";
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