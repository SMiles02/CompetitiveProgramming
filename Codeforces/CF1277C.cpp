#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,k;
string s;
vector<int> v;

void solve()
{
    cin>>s;
    n=sz(s);
    v.push_back(-1);
    for (int i=0;i<n-2;++i)
    {
        if (s[i]=='t')
        {
            if (s[i+1]=='w'&&s[i+2]=='o')
            {
                if (i+4<n)
                {
                    if (s[i+3]=='n'&&s[i+4]=='e')
                    {
                        v.push_back(i+2);
                    }
                    else
                    {
                        v.push_back(i+1);
                    }
                }
                else
                {
                    v.push_back(i+1);
                }
            }
        }
        else if (s[i]=='o'&&i!=v.back())
        {
            if (s[i+1]=='n'&&s[i+2]=='e')
            {
                v.push_back(i+1);
            }
        }
    }
    k=sz(v);
    cout<<k-1<<"\n";
    for (int i=1;i<k;++i)
    {
        cout<<v[i]+1<<" ";
    }
    cout<<"\n";
    v.clear();
    s.clear();
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}