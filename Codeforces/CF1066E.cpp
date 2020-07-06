#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int mod=998244353;

string maker(int n)
{
    string s="";
    while (n--)
        s+="0";
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,cur=0;
    cin>>n>>m;
    string a,b,z;
    a=maker(max(m-n,0));
    b=maker(max(n-m,0));
    cin>>z;
    a+=z;
    cin>>z;
    b+=z;
    n=max(n,m);
    ll nums[n],ans=0;
    nums[n-1]=1;
    for (int i=n-2;i+1;--i)
        nums[i]=(nums[i+1]*2)%mod;
    for (int i=0;i<n;++i)
    {
        if (b[i]-'0')
            ++cur;
        if (a[i]-'0')
        {
            ans+=nums[i]*cur;
            ans%=mod;
        }
    }
    cout<<ans;
    return 0;
}