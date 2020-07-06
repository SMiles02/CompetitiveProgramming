#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

string to_upper(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    string s,k;
    cin>>n;
    cin>>s;
    for (int i=0;i<n;++i)
    {
        if (i>sz(s))
        {
            cin>>k;
            s+=" "+k;
        }
    }
    s=to_upper(s);
    for (int i=0;i<n;++i)
    {
        if (s[i]=='.')
        {
            cout<<"!!!";
        }
        else
        {
            cout<<s[i];
        }
    }
    return 0;
}