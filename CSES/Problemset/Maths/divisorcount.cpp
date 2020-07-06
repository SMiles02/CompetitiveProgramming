#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int x,ans,cur=0;
    cin>>x;
    while (!(x%2))
    {
        ++cur;
        x/=2;
    }
    ans=cur+1;
    for (int i=3;i<=sqrt(x);i+=2)
    {
        cur=0;
        while (!(x%i))
        {
            x/=i;
            ++cur;
        }
        ans*=(cur+1);
    }
    if (x>1)
    {
        ans*=2;
    }
    cout<<ans<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}