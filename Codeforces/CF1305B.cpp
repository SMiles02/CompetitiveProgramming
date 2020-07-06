#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int closingLeft[1000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k=0;
    string s;
    cin>>s;
    n=sz(s);
    for (int i=0;i<n;++i)
    {
        if (s[i]==')')
        {
            ++closingLeft[i];
        }
    }
    for (int i=n-2;i+1;--i)
    {
        closingLeft[i]+=closingLeft[i+1];
    }
    vector<int> v;
    for (int i=0;i<n;++i)
    {
        if (s[i]=='(')
        {
            if (k+1>closingLeft[i])
            {
                break;
            }
            ++k;
            v.push_back(i);
        }
    }
    for (int i=n-1;i+1&&k;--i)
    {
        if (s[i]==')')
        {
            --k;
            v.push_back(i);
        }
    }
    k=sz(v);
    sort(v.begin(), v.end());
    if (k)
    {
        cout<<"1\n"<<k<<"\n";
        for (int i=0;i<k;++i)
        {
            cout<<v[i]+1<<" ";
        }
    }
    else
    {
        cout<<0;
    }
    return 0;
}