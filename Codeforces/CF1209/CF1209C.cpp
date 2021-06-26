#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n;
string s;
int a[200000];

bool check(int x, bool b)
{
    int l1=0,l2=x-1;
    for (int i=0;i<n;++i)
    {
        if ((s[i]-'0')>=l2)
        {
            a[i]=2;
            l2=(s[i]-'0');
        }
        else
            a[i]=1;
    }
    l2=0;
    for (int i=0;i<n;++i)
    {
        if (a[i]==1)
        {
            if ((s[i]-'0')<l1)
                return 0;
            l1=(s[i]-'0');
        }
        else
        {
            if ((s[i]-'0')<l2)
                return 0;
            l2=(s[i]-'0');
        }
    }
    if (b)
    {
        for (int i=0;i<n;++i)
            cout<<a[i];
        cout<<"\n";
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    bool k;
    cin>>t;
    while (t--)
    {
        cin>>n;
        cin>>s;
        k=0;
        for (int i=0;i<10&&!k;++i)
        {
            k=check(i,0);
            if (k)
                k=check(i,1);
        }
        if (!k)
            cout<<"-\n";
    }
    return 0;
}