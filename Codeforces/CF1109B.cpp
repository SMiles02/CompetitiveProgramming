#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

string s;
int n;

bool palindrome(string& t)
{
    for (int i=0;i<n;++i)
        if (t[i]!=t[n-1-i])
            return 0;
    return 1;
}

bool works(int A, int B, int C, int D)
{
    string t="";
    for (int i=A;i<=B;++i)
        t+=s[i];
    for (int i=C;i<=D;++i)
        t+=s[i];
    if (palindrome(t)&&s!=t)
        return 1;
    return 0;
}

int f[26];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>s;
    n=sz(s);
    for (int i=0;i<n;++i)
        ++f[s[i]-'a'];
    for (int i=0;i<26;++i)
        if (f[i]==n)
        {
            cout<<"Impossible";
            return 0;
        }
    for (int i=0;i<26;++i)
        for (int j=0;j<26;++j)
            if (i!=j)
                if (f[i]==n-1&&f[j]==1)
                {
                    cout<<"Impossible";
                    return 0;
                }
    for (int i=0;i+1<n;++i)
        if (works(0,i,i+1,n-1)||works(i+1,n-1,0,i))
        {
            cout<<1;
            return 0;
        }
    cout<<2;
    return 0;
}