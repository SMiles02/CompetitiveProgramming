#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,l,r,m;
    string s;
    cin>>n;
    l=1;r=1000000000;
    cout<<"0 1"<<endl;
    cin>>s;
    --n;
    if (s[0]=='b')
    {
        while (n--)
        {
            m=l+(r-l)/2;
            cout<<m<<" 1"<<endl;
            cin>>s;
            if (s[0]=='b')
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
    }
    else
    {
        while (n--)
        {
            m=l+(r-l)/2;
            cout<<m<<" 1"<<endl;
            cin>>s;
            if (s[0]=='b')
            {
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
    }
    cout<<l<<" 2 "<<r<<" 0"<<endl;
    return 0;
}