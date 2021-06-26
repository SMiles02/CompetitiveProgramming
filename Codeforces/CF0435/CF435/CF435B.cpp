#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

string s;
int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k,maxi,maxiInd;
    cin>>s>>k;
    n=sz(s);
    for (int i=0;i<n;++i)
    {
        maxi=(s[i]-'0');
        for (int j=i+1;j<min(i+k+1,n);++j)
        {
            if ((s[j]-'0')>maxi)
            {
                maxi=(s[j]-'0');
                maxiInd=j;
            }
        }
        if (maxi!=(s[i]-'0'))
        {
            k-=(maxiInd-i);
            for (int j=maxiInd;j>i;--j)
            {
                swap(s[j],s[j-1]);
            }
        }
    }
    cout<<s;
    return 0;
}