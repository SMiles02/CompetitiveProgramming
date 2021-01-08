#include <bits/stdc++.h>
using namespace std;

int SUM(string s)
{
    int ans=0;
    for (auto i : s)
        ans+=(i-'0');
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s,t;
    cin>>s;
    cin>>t;
    cout<<max(SUM(s),SUM(t));
    return 0;
}