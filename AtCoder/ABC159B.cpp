#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int isPalindrome(string s)
{
    int n=sz(s);
    for (int i=0;i<n;++i)
    {
        if (s[i]!=s[n-1-i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    string s,t="";
    cin>>s;
    n=sz(s);
    if (!isPalindrome(s))
    {
        cout<<"No";
        return 0;
    }
    for (int i=0;i<((n-1)/2);++i)
    {
        t+=s[i];
    }
    if (!isPalindrome(t))
    {
        cout<<"No";
        return 0;
    }
    t.clear();
    for (int i=((n/2)+1);i<n;++i)
    {
        t+=s[i];
    }
    if (!isPalindrome(t))
    {
        cout<<"No";
        return 0;
    }
    cout<<"Yes";
    return 0;
}