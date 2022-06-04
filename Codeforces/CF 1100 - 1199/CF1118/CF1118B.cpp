#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,ans=0;
    cin>>n;
    int odds[n+1];
    int evens[n+1];
    odds[0]=0;
    evens[0]=0;
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        if (i%2)
        {
            odds[i]=odds[i-1]+k;
            evens[i]=evens[i-1];
        }
        else
        {
            odds[i]=odds[i-1];
            evens[i]=evens[i-1]+k;
        }
    }
    for (int i=1;i<=n;++i)
    {
        if (odds[i-1]+evens[n]-evens[i]==evens[i-1]+odds[n]-odds[i]) ++ans;
    }
    cout<<ans;
    return 0;
}