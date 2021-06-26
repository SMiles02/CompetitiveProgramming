#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k,ans=0,tot=0;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> v;
    if (s[0]=='W')
    {
        tot=1;
        ans=1;
    }
    for (int i=1;i<n;++i)
    {
        if (s[i]=='L')
        {
            if (tot)
            {
                if (s[i-1]=='L')
                    ++v.back();
                else
                    v.push_back(1);
            }
        }
        else
        {
            if (s[i-1]=='W')
                ans+=2;
            else
                ++ans;
            ++tot;
        }
    }
    if (k==0)
        cout<<ans<<"\n";
    else if (tot+k>=n)
        cout<<2*n-1<<"\n";
    else if (tot==0)
        cout<<2*k-1<<"\n";
    else
    {
        if (s[n-1]=='L')
            v.pop_back();
        sort(v.rbegin(), v.rend());
        while ((!v.empty())&&k>=v.back())
        {
            ans+=(2*v.back())+1;
            k-=v.back();
            v.pop_back();
        }
        ans+=2*k;
        cout<<ans<<"\n";
    }
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