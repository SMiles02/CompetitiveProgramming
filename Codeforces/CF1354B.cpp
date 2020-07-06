#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n;
string s;
int ans;

void order(int a, int b)
{
    int one=-100000000,two=-100000000;
    for (int i=0;i<n;++i)
    {
        if ((s[i]-'0')==a)
            one=i;
        else if ((s[i]-'0')==b)
            two=one;
        else
            ans=min(ans,i-two+1);
    }
}

void solve()
{
    cin>>s;
    n=sz(s);
    ans=1000000;
    order(1,2);
    order(1,3);
    order(2,1);
    order(2,3);
    order(3,1);
    order(3,2);
    if (ans==1000000)
        cout<<"0\n";
    else
        cout<<ans<<"\n";
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