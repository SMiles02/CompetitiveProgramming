#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,s,k;
    ll maxi=0,maxiInd=0,cur=0,index=0;
    cin>>n>>s;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        cur+=k;
        if (maxi<k)
        {
            maxi=k;
            maxiInd=i+1;
        }
        //cout<<cur-maxi<<" ! \n";
        if (cur-maxi<=s)
        {
            //cout<<"test, i="<<i<<"\n";
            index=maxiInd;
            //cout<<"index is now "<<index<<"\n";
        }
    }
    if (cur<=s)
    {
        cout<<"0\n";
        return;
    }
    cout<<index<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}