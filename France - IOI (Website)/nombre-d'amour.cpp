#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int getAns()
{
    int n,ans=0;
    string s;
    cin>>s;
    n=sz(s);
    for (int i=0;i<n;++i)
    {
        ans+=(s[i]-'A');
    }
    if (ans%9==0&&ans!=0)
    {
        return 9;
    }
    return ans%9;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout<<getAns()<<" "<<getAns();
    return 0;
}