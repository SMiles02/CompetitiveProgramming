#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int biggest(int n)
{
    int maxi=n%10;
    n/=10;
    while (n)
    {
        maxi=max(maxi,n%10);
        n/=10;
    }
    return maxi;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ans=0;
    cin>>n;
    while (n)
    {
        ++ans;
        n-=biggest(n);
    }
    cout<<ans;
    return 0;
}