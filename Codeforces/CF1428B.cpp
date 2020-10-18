#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,l=0,r=0,d=0,ans=0;
    cin>>n;
    string s;
    cin>>s;
    for (int i=0;i<n;++i)
    {
        if (s[i]=='<')
            ++l;
        else if (s[i]=='>')
            ++r;
        else
            ++d;
        if (s[i]=='-'||s[(i+1)%n]=='-')
            ++ans;
    }
    if (d+max(l,r)==n)
        cout<<n<<"\n";
    else
        cout<<ans<<"\n";
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