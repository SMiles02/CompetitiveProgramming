#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    ll ans=0,cur=0;
    string s;
    char c;
    map<char,int> availableLetters;
    cin>>n>>k;
    cin>>s;
    while (k--)
    {
        cin>>c;
        availableLetters[c]=1;
    }
    for (int i=0;i<n;++i)
    {
        if (availableLetters[s[i]])
        {
            ++cur;
        }
        else
        {
            ans+=((cur*(cur+1))/2);
            cur=0;
        }
    }
    cout<<ans+((cur*(cur+1))/2);
    return 0;
}