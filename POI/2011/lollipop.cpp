#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,o=0,e=0,c=0,l,r;
    pii odd;
    pii even;
    cin>>n>>m;
    string s;
    cin>>s;
    for (int i=0;i<n;++i)
    {
        if (s[i]=='T')
            c+=2;
        else
            c+=1;
        if (c&1)
        {
            if (c>o)
            {
                odd={0,i};
                o=c;
            }
        }
        else if (c>e)
        {
            even={0,i};
            e=c;
        }
    }
    c=0;
    for (int i=n-1;i+1;--i)
    {
        if (s[i]=='T')
            c+=2;
        else
            c+=1;
        if (c&1)
        {
            if (c>o)
            {
                odd={i,n-1};
                o=c;
            }
        }
        else if (c>e)
        {
            even={i,n-1};
            e=c;
        }
    }
    int dp[2*n+1][2];
    l=odd.first;r=odd.second;
    for (int i=o;i>0;i-=2)
    {
        dp[i][0]=l+1;
        dp[i][1]=r+1;
        if (s[l]=='T')
            ++l;
        else if (s[r]=='T')
            --r;
        else
        {
            ++l;
            --r;
        }
    }
    l=even.first;r=even.second;
    for (int i=e;i>0;i-=2)
    {
        dp[i][0]=l+1;
        dp[i][1]=r+1;
        if (s[l]=='T')
            ++l;
        else if (s[r]=='T')
            --r;
        else
        {
            ++l;
            --r;
        }
    }
    while (m--)
    {
        cin>>c;
        if ((c&1&&c<=o)||(!(c&1)&&c<=e))
            cout<<dp[c][0]<<" "<<dp[c][1]<<"\n";
        else 
            cout<<"NIE\n";
    }
    return 0;
}