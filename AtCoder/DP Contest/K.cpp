#include <bits/stdc++.h>
using namespace std;

bitset<100001> dp;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x;
    cin>>n>>k;
    vector<int> v(n);
    for (int& i : v)
        cin>>i;
    for (int i=1;i<=k;++i)
        for (int j : v)
            if (j<=i)
                dp[i]=dp[i]|!dp[i-j];
    if (dp[k])
        cout<<"First";
    else
        cout<<"Second";
    return 0;
}