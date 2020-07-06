#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,same;
    ll ans=0;
    cin>>n>>k;
    string s[n];
    string t;
    map<string,int> m;
    map<char,int> charToInt;
    map<int,char> intToChar;
    charToInt['S']=0;
    charToInt['E']=1;
    charToInt['T']=2;
    intToChar[0]='S';
    intToChar[1]='E';
    intToChar[2]='T';
    for (int i=0;i<n;++i)
    {
        cin>>s[i];
        ++m[s[i]];
    }
    for (int i=0;i<n;++i)
    {
        for (int j=i+1;j<n;++j)
        {
            t="";
            same=0;
            for (int x=0;x<k;++x)
            {
                if (s[i][x]==s[j][x])
                {
                    t+=s[i][x];
                    ++same;
                }
                else
                {
                    t+=intToChar[3-charToInt[s[i][x]]-charToInt[s[j][x]]];                    
                }
            }
            if (same==k)
            {
                ans+=m[t]-2;
            }
            else
            {
                ans+=m[t];
            }
        }
    }
    cout<<ans/3;
    return 0;
}