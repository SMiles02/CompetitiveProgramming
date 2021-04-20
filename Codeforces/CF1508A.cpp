#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,x,y,z,a,b,c;
    string s[3],t,u="01";
    cin>>n;
    for (int i=0;i<3;++i)
        cin>>s[i];
    for (int i=0;i<3;++i)
        for (int j=0;j<i;++j)
            if (i!=j)
            {
                t="";
                x=y=z=0;
                while (x<n*2||y<n*2)
                {
                    a=b=0;
                    while (x<n*2&&(s[i][x]-'0')==z)
                    {
                        ++x;
                        ++a;
                    }
                    while (y<n*2&&(s[j][y]-'0')==z)
                    {
                        ++y;
                        ++b;
                    }
                    c=max(a,b);
                    while (c--)
                        t+=u[z];
                    z^=1;
                }
                if (sz(t)<=3*n)
                {
                    cout<<t<<"\n";
                    return;
                }
                t="";
                x=y=0;
                z=1;
                while (x<n*2||y<n*2)
                {
                    a=b=0;
                    while (x<n*2&&(s[i][x]-'0')==z)
                    {
                        ++x;
                        ++a;
                    }
                    while (y<n*2&&(s[j][y]-'0')==z)
                    {
                        ++y;
                        ++b;
                    }
                    c=max(a,b);
                    while (c--)
                        t+=u[z];
                    z^=1;
                }
                if (sz(t)<=3*n)
                {
                    cout<<t<<"\n";
                    return;
                }
            }
    cerr<<s[0]<<endl<<s[1]<<endl<<s[2]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}