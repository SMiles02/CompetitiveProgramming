#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
        return 1;
    int res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
string to_upper(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    ll ans=0;
    string s;
    cin>>n;
    cin>>s;
    if (n==1)
    {
        cout<<0;
        return 0;
    }
    int dp[n+1][2];
    dp[n-1][0]=n;
    dp[n-1][1]=n;
    dp[n][0]=n;
    dp[n][1]=n;
    for (int i=n-2;i>-1;--i)
    {
        if (s[i+1]=='A')
        {
            dp[i][0]=i+1;
            dp[i][1]=dp[i+1][1];
            if (s[i]=='A')
            {
                ans+=max(0,n-dp[i][1]-1)+(dp[i][1]-i-1);
                //cout<<i<<" "<<max(0,n-dp[i][1]-1)+(dp[i][1]-i-1)<<"\n";
            }
            else
            {
                ans+=(n-dp[i][1]);
                //cout<<i<<" "<<n-dp[i][1]<<"\n";
            }
        }
        else
        {
            dp[i][1]=i+1;
            dp[i][0]=dp[i+1][0];
            if (s[i]=='B')
            {
                ans+=max(0,n-dp[i][0]-1)+(dp[i][0]-i-1);
                //cout<<i<<" "<<max(0,n-dp[i][0]-1)+(dp[i][0]-i-1)<<"\n";
            }
            else
            {
                ans+=(n-dp[i][0]);
                //cout<<i<<" "<<n-dp[i][0]<<"\n";
            }
        }
    }
    cout<<ans;
    return 0;
}