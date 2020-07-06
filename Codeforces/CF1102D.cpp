#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    string s;
    cin>>n;
    cin>>s;
    int a[3];
    a[0]=0;a[1]=0;a[2]=0;
    for (int i=0;i<n;++i)
    {
        ++a[(s[i]-'0')];
    }
    for (int i=0;i<n&&a[0]<n/3;++i)
    {
        if (a[(s[i]-'0')]>n/3)
        {
            --a[(s[i]-'0')];
            ++a[0];
            s[i]='0';
        }
    }
    for (int i=n-1;i+1&&a[2]<n/3;--i)
    {
        if (a[s[i]-'0']>n/3)
        {
            --a[(s[i]-'0')];
            ++a[2];
            s[i]='2';
        }
    }
    for (int i=0;i<n&&a[1]<n/3&&a[2]>n/3;++i)
    {
        if (s[i]=='2')
        {
            --a[2];
            ++a[1];
            s[i]='1';
        }
    }
    for (int i=n-1;i+1&&a[1]<n/3&&a[0]>n/3;--i)
    {
        if (s[i]=='0')
        {
            --a[0];
            ++a[1];
            s[i]='1';
        }
    }
    cout<<s;
    return 0;
}