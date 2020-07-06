#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,r,c,excess,cur;
    string s;
    cin>>s;
    n=sz(s);
    for (int i=1;i<6;++i)
    {
        if (20*i>=n)
        {
            r=i;
            break;
        }
    }
    for (int j=1;j<21;++j)
    {
        if (r*j>=n)
        {
            c=j;
            break;
        }
    }
    excess=(r*c)-n;
    cur=0;
    cout<<r<<" "<<c<<"\n";
    for (int i=0;i<r;++i)
    {
        if (excess)
        {
            cout<<"*";
            --excess;
            for (int j=1;j<c;++j)
            {
                cout<<s[cur];
                ++cur;
            }
        }
        else
        {
            for (int j=0;j<c;++j)
            {
                cout<<s[cur];
                ++cur;
            }
        }
        cout<<"\n";
    }
    return 0;
}