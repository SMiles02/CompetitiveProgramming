#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    int n;
    cin>>s;
    n=sz(s);
    for (int i=0;i<n;++i)
    {
        if (!((s[i]-'0')%8))
        {
            cout<<"YES\n";
            cout<<s[i];
            return 0;
        }
    }
    if (n==1)
    {
        cout<<"NO\n";
        return 0;
    }
    for (int i=0;i<n;++i)
    {
        for (int j=i+1;j<n;++j)
        {
            if (!(((s[i]-'0')*10+(s[j]-'0'))%8))
            {
                cout<<"YES\n";
                cout<<s[i]<<s[j];
                return 0;
            }
        }
    }
    if (n==2)
    {
        cout<<"NO\n";
        return 0;
    }
    for (int i=0;i<n;++i)
    {
        for (int j=i+1;j<n;++j)
        {
            for (int k=j+1;k<n;++k)
            {
                if (!(((s[i]-'0')*100+(s[j]-'0')*10+(s[k]-'0'))%8))
                {
                    cout<<"YES\n";
                    cout<<s[i]<<s[j]<<s[k];
                    return 0;
                }
            }
        }
    }
    cout<<"NO";
    return 0;
}