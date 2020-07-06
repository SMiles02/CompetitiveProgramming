#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,oneCount=0;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        if (a[i]==1)
        {
            ++oneCount;
        }
    }
    if (oneCount)
    {
        cout<<n-oneCount;
        return 0;
    }
    if (n==1)
    {
        cout<<-1;
        return 0;
    }
    int found=0,cur;
    for (int i=0;i<n-1;++i)
    {
        cur=gcd(a[i],a[i+1]);
        for (int j=i+1;j<n;++j)
        {
            cur=gcd(cur,a[j]);
            if (cur==1)
            {
                if (found)
                {
                    found=min(found,j-i);
                }
                else
                {
                    found=j-i;
                }
            }
        }
    }
    if (found)
    {
        cout<<found+n-1;
    }
    else
    {
        cout<<-1;
    }
    return 0;
}