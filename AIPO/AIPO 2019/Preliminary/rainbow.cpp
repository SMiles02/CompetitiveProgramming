#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int dp[150][150];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x;
    cin>>n;
    cin>>x;
    vector<int> v;
    v.push_back(x);
    for (int i=1;i<n;++i)
    {
    	cin>>x;
    	if (x!=v.back())
    		v.push_back(x);
    }
    n=sz(v);
    for (int j=0;j<n;++j)
    	for (int i=0;i+j<n;++i)
    	{
    		dp[i][i+j]=j+1;
    		for (int k=i;k<i+j;++k)
    		{
    			if (v[i]==v[i+j]&&v[k]==v[k+1])
    				dp[i][i+j]=min(dp[i][i+j],dp[i][k]+dp[k+1][i+j]-2);
    			else if (v[i]==v[i+j])
    				dp[i][i+j]=min(dp[i][i+j],dp[i][k]+dp[k+1][i+j]-1);
    			else
    				dp[i][i+j]=min(dp[i][i+j],dp[i][k]+dp[k+1][i+j]);
    		}
    	}
    cout<<dp[0][n-1];
    return 0;
}