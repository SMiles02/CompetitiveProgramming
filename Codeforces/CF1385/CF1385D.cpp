#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

string s;

int f(int l, int r, int n, char c)
{
    if (n==1)
    {
        if (s[l]==c)
            return 0;
        return 1;
    }
    int a1=0,a2=0;
    for (int i=l;i<l+n/2;++i)
        if (s[i]!=c)
            ++a1;
    for (int i=l+n/2;i<r;++i)
        if (s[i]!=c)
            ++a2;
    char d=c;
    ++d;
    return min(a2+f(l,l+n/2,n/2,d),a1+f(l+n/2,r,n/2,d));
}

void solve()
{
    int n;
    cin>>n;
    cin>>s;
    cout<<f(0,n,n,'a')<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}