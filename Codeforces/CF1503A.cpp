#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,x=0,y=1,z=1;
    cin>>n;
    string s,a="(",b="(";
    cin>>s;
    for (auto i : s)
        if (i=='0')
            x^=1;
    if (s[0]=='0'||s[n-1]=='0'||x)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for (int i=1;i+1<n;++i)
    {
        if (s[i]=='1')
        {
            if ((x&&y>0)||(!x&&y>1))
            {
                a+=')';
                b+=')';
                --y;
                --z;
            }
            else
            {
                a+='(';
                b+='(';
                ++y;
                ++z;
            }
        }
        else
        {
            x^=1;
            if (x)
            {
                a+=')';
                b+='(';
                --y;
                ++z;
            }
            else
            {
                a+='(';
                b+=')';
                ++y;
                --z;
            }
        }
    }
    a+=')';b+=')';
    cout<<a<<"\n"<<b<<"\n";
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