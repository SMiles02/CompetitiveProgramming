#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,unique=0,pointer=0,have=0,mini;
    string s;
    cin>>n;
    mini=n+1;
    cin>>s;
    map<char,int> m;
    for (int i=0;i<n;++i)
    {
        if (!m[s[i]])
        {
            m[s[i]]=1;
            ++unique;
        }
    }
    //cout<<unique<<"\n";
    m.clear();
    for (int i=0;i<n;++i)
    {
        ++m[s[i]];
        if (m[s[i]]>1)
        {
            for (pointer=pointer;m[s[pointer]]>1;++pointer)
            {
                --m[s[pointer]];
            }
        }
        else
        {
            ++have;
        }
        if (have>=unique)
        {
            mini=min(mini,i-pointer+1);
        }
        //cout<<i<<": "<<have<<"\n";
    }
    cout<<mini;
    return 0;
}