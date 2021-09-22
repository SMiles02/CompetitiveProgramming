#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int add(int a, int b)
{
    a+=b;
    if (a>=MOD)
        a-=MOD;
    return a;
}

int mul(int a, int b)
{
    return (1LL*a*b)%MOD;
}

void solve()
{
    int n,ans=0,cur=0,id;
    cin>>n;
    string s;
    char l = '?';
    cin>>s;
    for (int i=0;i<n;++i)
        if (s[i]!='F')
        {
            if (l!='?'&&s[i]!=l)
                ans=add(ans,mul(id+1,n-i));
            l=s[i];
            id=i;
        }
    cout<<ans<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    for (int i=1;i<=t;++i)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}