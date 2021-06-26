#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve(int n, string s)
{
    if (s[0]=='1'||s[n-1]=='1')
    {
        cout<<2*n<<"\n";
        return;
    }
    int first=0,last=0;
    for (int i=1;i<n;++i)
    {
        if (s[i]=='1')
        {
            last=i;
            if (!first)
            {
                first=i;
            }
        }
    }
    if (!last)
    {
        cout<<n<<"\n";
        return;
    }
    cout<<max(2*(n-first),2*(last+1))<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t,n;
    string s;
    cin>>t;
    while (t--)
    {
        cin>>n;
        cin>>s;
        solve(n,s);
    }
    return 0;
}