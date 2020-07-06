#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

int n,p;
int dp[2000];
int a[2000];
bool divP[2001];

bool check(int k)
{
    for (int i=0;i<n;++i)
        dp[i]=0;
    for (int i=0;i<n;++i)
    {
        if (k+n-1<a[i])
            return 0;
        ++dp[max(0,a[i]-k)];
    }
    for (int i=1;i<n;++i)
        dp[i]+=dp[i-1];
    for (int i=0;i<n;++i)
        if (divP[max(0,dp[i]-i)])
            return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>p;
    for (int i=0;i<2001;++i)
        if (i%p==0)
            divP[i]=1;
    vector<int> ans;
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int x=1;x<=2000;++x)
        if (check(x))
            ans.push_back(x);
    cout<<sz(ans)<<"\n";
    for (int i : ans)
        cout<<i<<" ";
    return 0;
}